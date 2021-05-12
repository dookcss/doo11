//
// Created by dadoum on 12/05/2021.
//

#include "NativeLibrary.hpp"

#include <hybris/common/dlfcn.h>
#include <hybris/common/hooks.h>

#include <dlfcn.h>
#include <filesystem>
#include <fmt/format.h>
#include <memory>

std::unordered_map<std::string, void*> hooked_functions;
std::unordered_map<std::string, std::function<void*(std::string const&)>> hooked_classes;

bool NativeLibrary::isInitialized;
jnivm::VM NativeLibrary::vm;

void *hook_callback(const char *symbol_name, const char *requester) {
	if (hooked_classes[requester]) {
		auto fct = hooked_classes[requester](symbol_name);
		if (fct)
			return fct;
	}

	return hooked_functions[symbol_name];
}

void NativeLibrary::initialize() {
	hybris_set_hook_callback(hook_callback);
}

void NativeLibrary::addGlobalHook(std::string const& symbol, void *replacement) {
	hooked_functions[symbol] = replacement;
}

void NativeLibrary::hookSymbol(std::string const& symbol, void *replacement) {
	hooks[symbol] = replacement;
}

NativeLibrary::NativeLibrary(std::string const& path) {
	if (!isInitialized) {
		initialize();
	}

	printf("Chargement de %s... ", path.c_str());
	fflush(stdout);
	handle = hybris_dlopen(path.c_str(), RTLD_LAZY);
	if (!handle) {
		throw LibraryLoadException(hybris_dlerror());
	}

	try {
		auto JNI_OnLoad =
			(jint(*)(JavaVM * vm, void *reserved)) loadSymbol("JNI_OnLoad");
		printf("invocation de JNI_OnLoad... ", path.c_str());
		fflush(stdout);
		auto code = JNI_OnLoad(vm.GetJavaVM(), 0);
		printf("code %d retourné... ", code);
		fflush(stdout);
	} catch(std::exception ex) {

	}
	std::filesystem::path name(path);

	hooked_classes[name.filename()] = [this](std::string const &symbol) {
	  return this->getHookedSymbol(symbol);
	};;

	printf("succès !\n", path.c_str());
	fflush(stdout);
}

void *NativeLibrary::getHookedSymbol(const std::string &symbol) {
	return hooks[symbol];
}

void *NativeLibrary::loadSymbol(std::string const& symbol) {
	auto func = hybris_dlsym(handle, symbol.c_str());
	if (!func) {
		throw LibraryLoadException(fmt::format("Aucun symbole du nom de \"{0}\" n'a été trouvé", symbol));
	}
	return func;
}

NativeLibrary::~NativeLibrary() {
	hybris_dlclose(handle);
}

LibraryLoadException::LibraryLoadException(const std::string &message){
	text = message;
}

const char* LibraryLoadException::what() const throw() {
	return text.c_str();
}
