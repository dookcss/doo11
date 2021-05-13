//
// Created by dadoum on 13/05/2021.
//

#ifndef PROVISION_LIBRARYBUNDLE_HPP
#define PROVISION_LIBRARYBUNDLE_HPP

#include <NativeLibrary.hpp>

class LibraryBundle {
  public:
	static std::unique_ptr<NativeLibrary> ld_android;
	static std::unique_ptr<NativeLibrary> libdl;
	static std::unique_ptr<NativeLibrary> libc;
	static std::unique_ptr<NativeLibrary> log;
	static std::unique_ptr<NativeLibrary> m;
	static std::unique_ptr<NativeLibrary> z;
	static std::unique_ptr<NativeLibrary> android;
	static std::unique_ptr<NativeLibrary> stdcpp;
	static std::unique_ptr<NativeLibrary> openSLES;
	static std::unique_ptr<NativeLibrary> cpp_shared;
	static std::unique_ptr<NativeLibrary> xml2;
	static std::unique_ptr<NativeLibrary> curl;
	static std::unique_ptr<NativeLibrary> coreAdi;
	static std::unique_ptr<NativeLibrary> coreLskd;
	static std::unique_ptr<NativeLibrary> coreFp;
	static std::unique_ptr<NativeLibrary> blocks;
	static std::unique_ptr<NativeLibrary> dispatch;
	static std::unique_ptr<NativeLibrary> icudata;
	static std::unique_ptr<NativeLibrary> icuuc;
	static std::unique_ptr<NativeLibrary> icui18n;
	static std::unique_ptr<NativeLibrary> daapkit;
	static std::unique_ptr<NativeLibrary> coreFoundation;
	static std::unique_ptr<NativeLibrary> mediaPlatform;
	static std::unique_ptr<NativeLibrary> storeServicesCore;
	static std::unique_ptr<NativeLibrary> mediaLibraryCore;
	static std::unique_ptr<NativeLibrary> androidAppMusic;

	static void initializeBundle();
};

#endif // PROVISION_LIBRARYBUNDLE_HPP
