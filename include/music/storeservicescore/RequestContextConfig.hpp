//
// Created by dadoum on 13/05/2021.
//

#ifndef PROVISION_REQUESTCONTEXTCONFIG_HPP
#define PROVISION_REQUESTCONTEXTCONFIG_HPP

#include <LibraryBundle.hpp>
#include <music/androidstoreservices/AndroidRequestContextObserver.hpp>
#include <music/mediaplatform/ContentBundle.hpp>
#include <music/mediaplatform/HTTPProxy.hpp>

namespace storeservicescore {
	class RequestContextConfig {
	  public:
		std::shared_ptr<void> handle;
		RequestContextConfig(RequestContextConfig const&) = delete;
		RequestContextConfig& operator=(RequestContextConfig const&) = delete;
		RequestContextConfig();
		~RequestContextConfig();
		const std::unique_ptr<NativeLibrary> &LIBRARY = LibraryBundle::androidAppMusic;

		void setHTTPProxy(mediaplatform::HTTPProxy const &);
		void setDeviceModel(std::string const &);
		void setBuildVersion(std::string const &);
		void setContentBundle(std::shared_ptr<mediaplatform::ContentBundle> const &);
		void setProductVersion(std::string const &);
		void setResetHttpCache(bool);
		void setClientIdentifier(std::string const &);
		void setLocaleIdentifier(std::string const &);
		void setBaseDirectoryPath(std::string const &);
		void setVersionIdentifier(std::string const &);
		void setLanguageIdentifier(std::string const &);
		void setPlatformIdentifier(std::string const &);
		void setFairPlayDirectoryPath(std::string const &);
		void setRequestContextObserver(androidstoreservices::AndroidRequestContextObserver const &);
		std::string deviceModel() const;
		std::string buildVersion() const;
		std::shared_ptr<mediaplatform::ContentBundle> contentBundle() const;
		std::string productVersion() const;
		bool resetHttpCache() const;
		std::string clientIdentifier() const;
		std::string localeIdentifier() const;
		std::string baseDirectoryPath() const;
		std::string versionIdentifier() const;
		std::string languageIdentifier() const;
		std::string platformIdentifier() const;
		std::string fairPlayDirectoryPath() const;
		std::shared_ptr<androidstoreservices::AndroidRequestContextObserver> requestContextObserver() const;
		std::string userAgent() const;
	};
}

#endif // PROVISION_REQUESTCONTEXTCONFIG_HPP
