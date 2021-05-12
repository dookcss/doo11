#include <hybris/common/dlfcn.h>

#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <unistd.h>
#include <NativeLibrary.hpp>


// https://stackoverflow.com/questions/10723403/char-array-to-hex-string-c
char const hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
					  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

const char *logs[] = {"INCONNU",   "DÉFAUT",	  "VERBEUX",
					  "DÉBOGGAGE", "INFORMATION", "AVERTISSEMENT",
					  "ERREUR",	   "FATAL",		  "SILENCIEUX"};



std::string byte_2_str(char *bytes, int size) {
	std::string str;
	for (int i = 0; i < size; ++i) {
		const char ch = bytes[i];
		str.append(&hex[(ch & 0xF0) >> 4], 1);
		str.append(&hex[ch & 0xF], 1);
	}
	return str;
}

bool logEnabledForPriority() { return true; }

void __android_log_write(int prio, const char *tag, const char *text) {
	printf(">>> Journal d'Android >>> [%s] [%s]: %s\n", logs[prio], tag, text);
	fflush(stdout);
}

void initLibs() {
	printf("Initialisation des bibliothèques...\n");
	fflush(stdout);

	printf("Les bibliothèques ont été chargé avec succès !\n");
	fflush(stdout);
}

int main() {
	NativeLibrary::addGlobalHook("__android_log_write",
								 (void *)__android_log_write);
	NativeLibrary::addGlobalHook(
		"_ZN13mediaplatform26DebugLogEnabledForPriorityENS_11LogPriorityE",
		(void *)logEnabledForPriority);

	printf("Début de la procédure d'approvisionnement...\n");
	fflush(stdout);

	NativeLibrary libdl("lib-ndk/libdl.so");
	NativeLibrary libc("lib-ndk/libc.so");
	NativeLibrary cpp_shared("lib32/libc++_shared.so");
	NativeLibrary log("lib-ndk/liblog.so");
	NativeLibrary m("lib-ndk/libm.so");
	NativeLibrary z("lib-ndk/libz.so");
	NativeLibrary android("lib-ndk/libandroid.so");
	NativeLibrary xml2("lib32/libxml2.so");
	NativeLibrary stdcpp("lib-ndk/libstdc++.so");
	NativeLibrary curl("lib32/libcurl.so");
	NativeLibrary coreAdi("lib32/libCoreADI.so");
	NativeLibrary coreLskd("lib32/libCoreLSKD.so");
	NativeLibrary coreFp("lib32/libCoreFP.so");
	NativeLibrary blocks("lib32/libBlocksRuntime.so");
	NativeLibrary dispatch("lib32/libdispatch.so");
	NativeLibrary icudata("lib32/libicudata_sv_apple.so");
	NativeLibrary icuuc("lib32/libicuuc_sv_apple.so");
	NativeLibrary icui18n("lib32/libicui18n_sv_apple.so");
	NativeLibrary daapkit("lib32/libdaapkit.so");
	NativeLibrary coreFoundation("lib32/libCoreFoundation.so");
	NativeLibrary mediaPlatform("lib32/libmediaplatform.so");
	NativeLibrary storeServicesCore("lib32/libstoreservicescore.so");
	NativeLibrary mediaLibraryCore("lib32/libmedialibrarycore.so");
	NativeLibrary openSLES("lib-ndk/libOpenSLES.so");
	NativeLibrary androidAppMusic("lib32/libandroidappmusic.so");

	printf(
		"> Création du contexte des requêtes (objet natif: RequestContext)\n");
	fflush(stdout);
	auto RequestContext__ctor =
		(void (*)(void *self, std::string databasePath))storeServicesCore.loadSymbol(
			"_ZN17storeservicescore14RequestContextC1ERKNSt6__ndk112basic_"
			"stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");

	std::string home;
	home += getenv("HOME");
	std::string str = home;
	str += "/.config/hxsign/";
	std::filesystem::path file = std::filesystem::absolute(str);
	if (std::filesystem::exists(file) ||
		std::filesystem::create_directory(file)) {
		// str += "dbPath.absolutePath";
	} else {
		str = ":memory:";
	}

	void *context[0xff];
	(*RequestContext__ctor)(context, str);

	printf(" > Génération d'un identifiant unique...\n");
	fflush(stdout);

	auto machineIdFile = fopen("/etc/machine-id", "r");

	char androidIdChr[16];
	fread(androidIdChr, 16, 1, machineIdFile);
	fclose(machineIdFile);
	std::string androidId = androidIdChr;
	char requestContextConfig[0xfff];

	printf(" > Création de sa configuration (objet natif: "
		   "RequestContextConfig)\n");
	fflush(stdout);

	printf("  > Initialisation de champs triviaux\n");
	fflush(stdout);
	{
		auto setBaseDirectoryPath =
			(void (*)(void *self, std::string baseDirectoryPath))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig20setBaseDirectory"
					"PathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setBaseDirectoryPath(requestContextConfig, str);
	}
	{
		auto setClientIdentifier =
			(void (*)(void *self, std::string clientIdentifier))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig19setClientIdentif"
					"ierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setClientIdentifier(requestContextConfig, "Music"); // Xcode
	}
	{
		auto setVersionIdentifier =
			(void (*)(void *self, std::string versionIdentifier))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig20setVersionIdenti"
					"fierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setVersionIdentifier(requestContextConfig, "4.3"); // 11.2
	}
	{
		auto setPlatformIdentifier =
			(void (*)(void *self, std::string platformIdentifier))
				storeServicesCore.loadSymbol("_ZN17storeservicescore20RequestContextConfig21setPlatformIdent"
											 "ifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
											 "9allocatorIcEEEE");
		setPlatformIdentifier(requestContextConfig, "Android"); // Linux
	}
	{
		auto setProductVersion =
			(void (*)(void *self, std::string productVersion))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig17setProductVersio"
					"nERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setProductVersion(requestContextConfig, "10.0.0"); // 5.11.2
	}
	{
		auto setDeviceModel =
			(void (*)(void *self, std::string deviceModel))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig14setDeviceModelER"
					"KNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setDeviceModel(requestContextConfig,
					   "Google Pixel 3a"); // HP ProBook 430 G5
	}
	{
		auto setBuildVersion =
			(void (*)(void *self, std::string buildVersion))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig15setBuildVersionE"
					"RKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setBuildVersion(requestContextConfig, "5803371"); // Android 10	// 0
	}
	{
		auto setLocaleIdentifier =
			(void (*)(void *self, std::string localeIdentifier))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig19setLocaleIdentif"
					"ierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
					"9allocatorIcEEEE");
		setLocaleIdentifier(requestContextConfig, "fr_FR"); // fr_FR
	}
	{
		auto setLanguageIdentifier =
			(void (*)(void *self, std::string languageIdentifier))
				storeServicesCore.loadSymbol("_ZN17storeservicescore20RequestContextConfig21setLanguageIdent"
											 "ifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_"
											 "9allocatorIcEEEE");
		setLanguageIdentifier(requestContextConfig, "fr-FR"); // fr-FR
	}
	printf("  > Création de la représentation du proxy (objet natif: "
		   "HTTPProxy)\n");
	fflush(stdout);
	{
		char httpProxy[20];
		{
			unsigned short u = 80;
			auto HTTPProxy_ctor =
				(void (*)(void *self, int use_proxy, std::string ip,
						  unsigned short *port))mediaPlatform
					.loadSymbol("_ZN13mediaplatform9HTTPProxyC1ENS0_"
								"4TypeERKNSt6__ndk112basic_stringIcNS2_11char_"
								"traitsIcEENS2_9allocatorIcEEEERKt");
			(*HTTPProxy_ctor)(&httpProxy, 0, "", &u);
		}
		{
			auto setHTTPProxy = (void (*)(void *self, void *httpProxy))
									storeServicesCore.loadSymbol(
										"_ZN17storeservicescore20RequestContextConfig12setHTTPProxy"
										"ERKN13mediaplatform9HTTPProxyE");
			setHTTPProxy(requestContextConfig, httpProxy);
		}
	}

	printf("  > Initialisation de champs triviaux\n");
	fflush(stdout);
	{
		auto setResetHttpCache =
			(void (*)(void *self, bool resetHttpCache))storeServicesCore
				.loadSymbol("_ZN17storeservicescore20RequestContextConfi"
							  "g17setResetHttpCacheEb");
		setResetHttpCache(
			requestContextConfig,
			false); // Valeur par défaut, mais en vrai un true se tente, c'est
					// géré par les préférences de l'appli.
	}

	{
		auto setRequestContextObserver =
			(void (*)(void *self,
					  std::shared_ptr<void *> requestContextObserver))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig25set"
					"RequestContextObserverERKNSt6__ndk110shared_"
					"ptrINS_22RequestContextObserverEEE");
		void *requestContextObserver;

		setRequestContextObserver(
			requestContextConfig,
			std::make_shared<void *>(
				requestContextObserver)); // À revérifier, pas sûr de mon coup.
	}

	printf("  > Création de l'identifiant de l'appareil (objet natif: "
		   "DeviceGUID)\n");
	fflush(stdout);
	{
		const std::string savedGuid = "";
		{
			auto FootHill__config =
				(int (*)(std::string const &savedGuid))
					androidAppMusic.loadSymbol(
					"_ZN14FootHillConfig6configERKNSt6__ndk112basic_"
					"stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE");
			(*FootHill__config)(savedGuid);
			fflush(stdout);
		}

		{
			auto DeviceGUID__ctor =
				(std::shared_ptr<void>(*)(void))storeServicesCore.loadSymbol(
					"_ZN17storeservicescore10DeviceGUID8instanceEv");
			std::string guidstr = "";
			auto guid = (*DeviceGUID__ctor)();

			if (guid != NULL) {
				auto DeviceGUID__configure =
					(void *(*)(std::string const &, void *,
							   unsigned int const &, bool const &))
						storeServicesCore.loadSymbol(
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
				auto storeErrorCode = (*DeviceGUID__configure)(
					androidId, (void *)&savedGuid, 29, true);
				if (storeErrorCode == 0) {
					auto DeviceGUID__guid =
						(std::shared_ptr<void>(*)(void *self))
							storeServicesCore.loadSymbol(
								"_ZN17storeservicescore10DeviceGUID4guidEv");
					auto dataptr = (*DeviceGUID__guid)(guid.get());
					printf(" %x \n", dataptr.get());
					fflush(stdout);
					if (dataptr != NULL) {
						printf("finalisation... ");
						auto Data__bytes = (char *(*)(void *self))
					mediaPlatform.loadSymbol("_ZNK13mediaplatform4Data5bytesEv");
						auto Data__length = (long (*)(void *self))
					mediaPlatform.loadSymbol("_ZNK13mediaplatform4Data6lengthEv");
						auto bytes = Data__bytes(dataptr.get());
						auto len = Data__length(dataptr.get());
						std::string guid = byte_2_str(bytes, len);
						printf("l'identifiant est %s ! ", guid.c_str());
						fflush(stdout);
					}
				} else {
					auto StoreErrorCondition_errorCode =
						(int (*)(void *const &))storeServicesCore.loadSymbol(
							"_ZNK17storeservicescore19StoreE"
							"rrorCondition9errorCodeEv");
					auto StoreErrorCondition_errorDescription =
						(const std::string &(*)(void *))storeServicesCore
							.loadSymbol("_ZNK17storeservicescore19StoreE"
										"rrorCondition4whatEv");
					auto stringDesc =
						StoreErrorCondition_errorDescription(storeErrorCode);
					printf("échec. Erreur %d: %s \n",
						   StoreErrorCondition_errorCode(storeErrorCode),
						   stringDesc.c_str());
				}
			}
		}
	}

	printf("  > Création du lot de stockage (objet natif: ContentBundle)\n");
	fflush(stdout);
	// auto setPresentationInterface 		= (void(*)(void* self,
	// std::shared_ptr<void>	presentationInterface 	))
	// hybris_dlsym(storeServicesCore,
	// "_ZN17storeservicescore20RequestContextConfig24setPresentationInterfaceERKNSt6__ndk110shared_ptrINS_21PresentationInterfaceEEE"
	// );

	{
		void *filePath[3][0x40];
		void *contentBundle[0x40];

		{

			auto filePath_ctor =
				(void (*)(void *self, std::string databasePath))
					mediaPlatform.loadSymbol(
					"_ZN13mediaplatform8FilePathC1ERKNSt6__ndk112basic_"
					"stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");

			filePath_ctor(&filePath[0], home + "/.config/hxsign");
			filePath_ctor(&filePath[1], home + "/.config/hxsign/cache");
			filePath_ctor(&filePath[2], home + "/.config/hxsign");

			{
				auto contentBundle_ctor = (void (*)(void *self, void *, void *,
													void *,
													std::vector<std::string> *))
					mediaPlatform.loadSymbol(
								 "_ZN13mediaplatform13ContentBundleC1ERKNS_"
								 "8FilePathES3_S3_"
								 "RKNSt6__ndk16vectorINS4_12basic_stringIcNS4_"
								 "11char_"
								 "traitsIcEENS4_9allocatorIcEEEENS9_ISB_EEEE");
				std::vector<std::string> langs = {"fr"};
				(*contentBundle_ctor)(contentBundle, &filePath[0], &filePath[1],
									  &filePath[2], &langs);
			}
		}

		{
			auto setContentBundle =
				(void (*)(void *self, std::shared_ptr<void *> contentBundle))
					storeServicesCore.loadSymbol(
						"_ZN17storeservicescore20RequestContextConfig1"
						"6setContentBundle"
						"ERKNSt6__ndk110shared_"
						"ptrIN13mediaplatform13ContentBundleEEE");
			setContentBundle(requestContextConfig,
							 std::make_shared<void *>(contentBundle));
		}
	}

	printf("  > Finalisation de la configuration... \n");
	fflush(stdout);
	{
		auto setFairPlayDirectoryPath =
			(void (*)(void *self, std::string const &fairPlayDirectoryPath))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore20RequestContextConfig24setFair"
					"PlayDirectoryPathERKNSt6__ndk112basic_stringIcNS1_"
					"11char_traitsIcEENS1_9allocatorIcEEEE");
		setFairPlayDirectoryPath(requestContextConfig,
								 home + "/.config/hxsign/fairPlay");
	}

	{
		auto RequestContext__init =
			(void (*)(void *self, std::shared_ptr<void *> config))
				storeServicesCore.loadSymbol(
					"_ZN17storeservicescore14RequestContext4initERKNSt6__"
					"ndk110shared_ptrINS_20RequestContextConfigEEE");

		RequestContext__init(context,
							 std::make_shared<void *>(requestContextConfig));
	}
	return 0;
}
