//
// Created by dadoum on 12/05/2021.
//

#ifndef PROVISION_NATIVELIBRARY_H
#define PROVISION_NATIVELIBRARY_H

#include <memory>
#include <string>

#include <jni.h>
#include <jnivm.h>

class NativeLibrary {
  private:
	static jnivm::VM vm;
	static bool isInitialized;
	void* handle;
	std::unordered_map<std::string, void*> hooks;

	static void initialize();
	void* getHookedSymbol(std::string const&);
  public:
	NativeLibrary(NativeLibrary const&) = delete;
	NativeLibrary& operator=(NativeLibrary const&) = delete;
	NativeLibrary& operator=(NativeLibrary &&) = default;

	NativeLibrary(std::string const& path);
	~NativeLibrary();

	void *loadSymbol(std::string const& symbol);
	void hookSymbol(std::string const& symbol, void *replacement);
	static void addGlobalHook(std::string const& symbol, void *replacement);
};

class LibraryLoadException: public std::exception
{
  private:
	std::string text;
  public:
	LibraryLoadException(LibraryLoadException const&) = delete;
	LibraryLoadException& operator=(LibraryLoadException const&) = delete;

	LibraryLoadException(std::string const& message);

	virtual const char* what() const throw();
};

#endif // PROVISION_NATIVELIBRARY_H
