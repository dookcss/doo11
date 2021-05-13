//
// Created by dadoum on 13/05/2021.
//

#include "LibraryBundle.hpp"

std::unique_ptr<NativeLibrary> LibraryBundle::ld_android;
std::unique_ptr<NativeLibrary> LibraryBundle::libdl;
std::unique_ptr<NativeLibrary> LibraryBundle::libc;
std::unique_ptr<NativeLibrary> LibraryBundle::log;
std::unique_ptr<NativeLibrary> LibraryBundle::m;
std::unique_ptr<NativeLibrary> LibraryBundle::z;
std::unique_ptr<NativeLibrary> LibraryBundle::android;
std::unique_ptr<NativeLibrary> LibraryBundle::stdcpp;
std::unique_ptr<NativeLibrary> LibraryBundle::openSLES;
std::unique_ptr<NativeLibrary> LibraryBundle::cpp_shared;
std::unique_ptr<NativeLibrary> LibraryBundle::xml2;
std::unique_ptr<NativeLibrary> LibraryBundle::curl;
std::unique_ptr<NativeLibrary> LibraryBundle::coreAdi;
std::unique_ptr<NativeLibrary> LibraryBundle::coreLskd;
std::unique_ptr<NativeLibrary> LibraryBundle::coreFp;
std::unique_ptr<NativeLibrary> LibraryBundle::blocks;
std::unique_ptr<NativeLibrary> LibraryBundle::dispatch;
std::unique_ptr<NativeLibrary> LibraryBundle::icudata;
std::unique_ptr<NativeLibrary> LibraryBundle::icuuc;
std::unique_ptr<NativeLibrary> LibraryBundle::icui18n;
std::unique_ptr<NativeLibrary> LibraryBundle::daapkit;
std::unique_ptr<NativeLibrary> LibraryBundle::coreFoundation;
std::unique_ptr<NativeLibrary> LibraryBundle::mediaPlatform;
std::unique_ptr<NativeLibrary> LibraryBundle::storeServicesCore;
std::unique_ptr<NativeLibrary> LibraryBundle::mediaLibraryCore;
std::unique_ptr<NativeLibrary> LibraryBundle::androidAppMusic;

void LibraryBundle::initializeBundle() {
	ld_android = std::make_unique<NativeLibrary>("libndk/ld-android.so");
	libdl = std::make_unique<NativeLibrary>("libndk/libdl.so");
	libc = std::make_unique<NativeLibrary>("libndk/libc.so");
	log = std::make_unique<NativeLibrary>("libndk/liblog.so");
	m = std::make_unique<NativeLibrary>("libndk/libm.so");
	z = std::make_unique<NativeLibrary>("libndk/libz.so");
	android = std::make_unique<NativeLibrary>("libndk/libandroid.so");
	stdcpp = std::make_unique<NativeLibrary>("libndk/libstdc++.so");
	openSLES = std::make_unique<NativeLibrary>("libndk/libOpenSLES.so");
	cpp_shared = std::make_unique<NativeLibrary>("lib32/libc++_shared.so");
	xml2 = std::make_unique<NativeLibrary>("lib32/libxml2.so");
	curl = std::make_unique<NativeLibrary>("lib32/libcurl.so");
	coreAdi = std::make_unique<NativeLibrary>("lib32/libCoreADI.so");
	coreLskd = std::make_unique<NativeLibrary>("lib32/libCoreLSKD.so");
	coreFp = std::make_unique<NativeLibrary>("lib32/libCoreFP.so");
	blocks = std::make_unique<NativeLibrary>("lib32/libBlocksRuntime.so");
	dispatch = std::make_unique<NativeLibrary>("lib32/libdispatch.so");
	icudata = std::make_unique<NativeLibrary>("lib32/libicudata_sv_apple.so");
	icuuc = std::make_unique<NativeLibrary>("lib32/libicuuc_sv_apple.so");
	icui18n = std::make_unique<NativeLibrary>("lib32/libicui18n_sv_apple.so");
	daapkit = std::make_unique<NativeLibrary>("lib32/libdaapkit.so");
	coreFoundation = std::make_unique<NativeLibrary>("lib32/libCoreFoundation.so");
	mediaPlatform = std::make_unique<NativeLibrary>("lib32/libmediaplatform.so");
	storeServicesCore = std::make_unique<NativeLibrary>("lib32/libstoreservicescore.so");
	mediaLibraryCore = std::make_unique<NativeLibrary>("lib32/libmedialibrarycore.so");
	androidAppMusic = std::make_unique<NativeLibrary>("lib32/libandroidappmusic.so");
}
