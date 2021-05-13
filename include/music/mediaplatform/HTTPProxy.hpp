//
// Created by dadoum on 13/05/2021.
//

#ifndef PROVISION_HTTPPROXY_HPP
#define PROVISION_HTTPPROXY_HPP

#include <LibraryBundle.hpp>
#include <NativeLibrary.hpp>
#include <memory>
namespace mediaplatform {
	class HTTPProxy {
	  public:
		std::shared_ptr<void> handle;
		HTTPProxy(HTTPProxy const&) = delete;
		HTTPProxy& operator=(HTTPProxy const&) = delete;
		HTTPProxy(std::shared_ptr<void>);
		HTTPProxy(int, std::string const&, unsigned short const&);
		const std::unique_ptr<NativeLibrary> &LIBRARY = LibraryBundle::mediaPlatform;
	};
} // namespace mediaplatform

#endif // PROVISION_HTTPPROXY_HPP
