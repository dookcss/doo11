//
// Created by dadoum on 13/05/2021.
//

#ifndef PROVISION_ANDROIDREQUESTCONTEXTOBSERVER_HPP
#define PROVISION_ANDROIDREQUESTCONTEXTOBSERVER_HPP

#include <LibraryBundle.hpp>
#include <NativeLibrary.hpp>
#include <memory>

namespace androidstoreservices {
	class AndroidRequestContextObserver {
	  public:
		std::shared_ptr<void> handle;
		AndroidRequestContextObserver(AndroidRequestContextObserver const&) = delete;
		AndroidRequestContextObserver& operator=(AndroidRequestContextObserver const&) = delete;
		AndroidRequestContextObserver(std::shared_ptr<void>);
		~AndroidRequestContextObserver();
		AndroidRequestContextObserver();
		const std::unique_ptr<NativeLibrary> &LIBRARY = LibraryBundle::androidAppMusic;
	};
} // namespace androidstoreservices

#endif // PROVISION_ANDROIDREQUESTCONTEXTOBSERVER_HPP
