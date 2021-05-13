#include <hybris/common/dlfcn.h>

#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include <LibraryBundle.hpp>
#include <NativeLibrary.hpp>
#include <fstream>
#include <music/storeservicescore/RequestContextConfig.hpp>
#include <stdlib.h>
#include <unistd.h>

// https://stackoverflow.com/questions/10723403/char-array-to-hex-string-c
char const hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

std::string const byte_2_str(char *bytes, int size) {
	std::string str;
	for (int i = 0; i < size; ++i) {
		const char ch = bytes[i];
		str.append(&hex[(ch & 0xF0) >> 4], 1);
		str.append(&hex[ch & 0xF], 1);
	}
	return str;
}

const std::string logs[] = {"INCONNU",		 "DÉFAUT", "VERBEUX", "DÉBOGGAGE", "INFORMATION",
							"AVERTISSEMENT", "ERREUR", "FATAL",	  "SILENCIEUX"};

bool logEnabledForPriority() { return true; }

void __android_log_write(int prio, const char *tag, const char *text) {
	printf(">>> Journal d'Android >>> [%s] [%s]: %s\n", logs[prio].c_str(), tag, text);
	fflush(stdout);
}

int main() {
	// On active le journal de toutes les actions, et on récupère ce qui y est noté pour l'afficher dans la console.
	NativeLibrary::addGlobalHook("__android_log_write", (void *)__android_log_write);
	NativeLibrary::addGlobalHook("_ZN13mediaplatform26DebugLogEnabledForPriorityENS_11LogPriorityE",
								 (void *)logEnabledForPriority);

	// On initialise les bibliothèques
	LibraryBundle::initializeBundle();

	printf("Début de la procédure d'approvisionnement...\n");
	fflush(stdout);

	printf("> Création du contexte des requêtes (objet natif: RequestContext)\n");
	fflush(stdout);
	auto RequestContext__ctor =
		(void (*)(void *self, std::string databasePath))LibraryBundle::storeServicesCore->loadSymbol(
			"_ZN17storeservicescore14RequestContextC1ERKNSt6__ndk112basic_"
			"stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");

	std::string home = std::getenv("HOME");
	std::string str = home;
	str += "/.config/hxsign/";
	std::filesystem::path file = std::filesystem::absolute(str);
	if (std::filesystem::exists(file) || std::filesystem::create_directory(file)) {
		// str += "dbPath.absolutePath";
	} else {
		str = ":memory:";
	}

	void *context[0xff];
	(*RequestContext__ctor)(context, str);

	printf(" > Génération d'un identifiant unique...\n");
	fflush(stdout);

	std::ifstream machineIdFile("/etc/machine-id");
	std::string androidId;
	std::copy_n(std::istreambuf_iterator<char>(machineIdFile.rdbuf()), 16, std::back_inserter(androidId));

	printf(" > Création de sa configuration (objet natif: RequestContextConfig)\n");
	fflush(stdout);
	storeservicescore::RequestContextConfig rcConfig;

	printf("  > Initialisation de champs triviaux\n");
	fflush(stdout);
	rcConfig.setBaseDirectoryPath(str);
	rcConfig.setClientIdentifier("Music"); // Xcode
	rcConfig.setVersionIdentifier("4.3"); // 11.2
	rcConfig.setPlatformIdentifier("Android"); // Linux
	rcConfig.setProductVersion("10.0.0"); // 5.11.2
	rcConfig.setDeviceModel("Google Pixel 3a"); // HP ProBook 430 G5
	rcConfig.setBuildVersion("5803371"); // Android 10	// 0
	rcConfig.setLocaleIdentifier("fr_FR"); // fr_FR
	rcConfig.setLanguageIdentifier("fr-FR"); // fr-FR

	mediaplatform::HTTPProxy proxy(0, "", 80);
	rcConfig.setHTTPProxy(proxy);
	rcConfig.setResetHttpCache(false); // Valeur par défaut, mais en vrai un true se tente

	androidstoreservices::AndroidRequestContextObserver rcObserver;
	rcConfig.setRequestContextObserver(rcObserver);

	/*{
		auto setRequestContextObserver = (void (*)(void *self, std::shared_ptr<void *> requestContextObserver))
											 LibraryBundle::storeServicesCore->loadSymbol(
												 "_ZN17storeservicescore20RequestContextConfig25set"
												 "RequestContextObserverERKNSt6__ndk110shared_"
												 "ptrINS_22RequestContextObserverEEE");
		void *requestContextObserver;

		setRequestContextObserver(
			rcConfig,
			std::make_shared<void *>(requestContextObserver)); // À revérifier, pas sûr de mon coup.
	}

	printf("  > Création de l'identifiant de l'appareil (objet natif: "
		   "DeviceGUID)\n");
	fflush(stdout);
	{
		const std::string savedGuid = "";
		{
			auto FootHill__config = (int (*)(std::string const &savedGuid))LibraryBundle::androidAppMusic->loadSymbol(
				"_ZN14FootHillConfig6configERKNSt6__ndk112basic_"
				"stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE");
			(*FootHill__config)(savedGuid);
			fflush(stdout);
		}

		{
			auto DeviceGUID__ctor = (std::shared_ptr<void>(*)(void))LibraryBundle::storeServicesCore->loadSymbol(
				"_ZN17storeservicescore10DeviceGUID8instanceEv");
			std::string guidstr = "";
			auto guid = (*DeviceGUID__ctor)();

			if (guid != NULL) {
				auto DeviceGUID__configure =
					(void *(*)(std::string const &, void *, unsigned int const &, bool const &))
						LibraryBundle::storeServicesCore->loadSymbol(
							"_ZN17storeservicescore10DeviceGUID9configureERKNSt"
							"6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
							"9allocatorIcEEEES9_RKjRKb");
				printf("   > Configuration du GUID... ");
				// DeviceGUID -> ??? -> FairPlay::config(string str) ->
				// FUN_000d6000(&&str) -> ADISetAndroidID
				// "Sph98paBcz"(str->cstr(), str->length) ->
				fflush(stdout);
				void *strplus;
				strplus = 0x0;
				auto storeErrorCode = (*DeviceGUID__configure)(androidId, (void *)&savedGuid, 29, true);
				if (storeErrorCode == 0) {
					auto DeviceGUID__guid =
						(std::shared_ptr<void>(*)(void *self))LibraryBundle::storeServicesCore->loadSymbol(
							"_ZN17storeservicescore10DeviceGUID4guidEv");
					auto dataptr = (*DeviceGUID__guid)(guid.get());
					printf(" %x \n", dataptr.get());
					fflush(stdout);
					if (dataptr != NULL) {
						printf("finalisation... ");
						auto Data__bytes = (char *(*)(void *self))LibraryBundle::mediaPlatform->loadSymbol(
							"_ZNK13mediaplatform4Data5bytesEv");
						auto Data__length = (long (*)(void *self))LibraryBundle::mediaPlatform->loadSymbol(
							"_ZNK13mediaplatform4Data6lengthEv");
						auto bytes = Data__bytes(dataptr.get());
						auto len = Data__length(dataptr.get());
						std::string guid = byte_2_str(bytes, len);
						printf("l'identifiant est %s ! ", guid.c_str());
						fflush(stdout);
					}
				} else {
					auto StoreErrorCondition_errorCode =
						(int (*)(void *const &))LibraryBundle::storeServicesCore->loadSymbol(
							"_ZNK17storeservicescore19StoreErrorCondition9errorCodeEv");
					auto StoreErrorCondition_errorDescription =
						(const std::string &(*)(void *))LibraryBundle::storeServicesCore->loadSymbol(
							"_ZNK17storeservicescore19StoreErrorCondition4whatEv");
					auto stringDesc = StoreErrorCondition_errorDescription(storeErrorCode);
					printf("échec. Erreur %d: %s \n", StoreErrorCondition_errorCode(storeErrorCode),
						   stringDesc.c_str());
				}
			}
		}
	}

	printf("  > Création du lot de stockage (objet natif: ContentBundle)\n");
	fflush(stdout);
	{
		void *filePath[3][0x40];
		void *contentBundle[0x40];

		{

			auto filePath_ctor =
				(void (*)(void *self, std::string databasePath))LibraryBundle::mediaPlatform->loadSymbol(
					"_ZN13mediaplatform8FilePathC1ERKNSt6__ndk112basic_"
					"stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");

			filePath_ctor(&filePath[0], home + "/.config/hxsign");
			filePath_ctor(&filePath[1], home + "/.config/hxsign/cache");
			filePath_ctor(&filePath[2], home + "/.config/hxsign");

			{
				auto contentBundle_ctor =
					(void (*)(void *self, void *, void *, void *, std::vector<std::string> *))
						LibraryBundle::mediaPlatform->loadSymbol("_ZN13mediaplatform13ContentBundleC1ERKNS_"
																 "8FilePathES3_S3_"
																 "RKNSt6__ndk16vectorINS4_12basic_stringIcNS4_"
																 "11char_"
																 "traitsIcEENS4_9allocatorIcEEEENS9_ISB_EEEE");
				std::vector<std::string> langs = {"fr"};
				(*contentBundle_ctor)(contentBundle, &filePath[0], &filePath[1], &filePath[2], &langs);
			}
		}

		{
			auto setContentBundle = (void (*)(void *self, std::shared_ptr<void *> contentBundle))
										LibraryBundle::storeServicesCore->loadSymbol(
											"_ZN17storeservicescore20RequestContextConfig1"
											"6setContentBundle"
											"ERKNSt6__ndk110shared_"
											"ptrIN13mediaplatform13ContentBundleEEE");
			setContentBundle(rcConfig, std::make_shared<void *>(contentBundle));
		}
	}

	printf("  > Finalisation de la configuration... \n");
	fflush(stdout);
	{
		auto setFairPlayDirectoryPath = (void (*)(void *self, std::string const &fairPlayDirectoryPath))
											LibraryBundle::storeServicesCore->loadSymbol(
												"_ZN17storeservicescore20RequestContextConfig24setFair"
												"PlayDirectoryPathERKNSt6__ndk112basic_stringIcNS1_"
												"11char_traitsIcEENS1_9allocatorIcEEEE");
		setFairPlayDirectoryPath(rcConfig, home + "/.config/hxsign/fairPlay");
	}

	{
		auto RequestContext__init =
			(void (*)(void *self, std::shared_ptr<void *> config))LibraryBundle::storeServicesCore->loadSymbol(
				"_ZN17storeservicescore14RequestContext4initERKNSt6__"
				"ndk110shared_ptrINS_20RequestContextConfigEEE");

		RequestContext__init(context, std::make_shared<void *>(rcConfig));
	}*/
	return 0;
}
