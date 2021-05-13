//
// Created by dadoum on 13/05/2021.
//

#include <music/androidstoreservices/AndroidRequestContextObserver.hpp>

androidstoreservices::AndroidRequestContextObserver::AndroidRequestContextObserver() {
	handle = std::make_shared<void*>();
}

androidstoreservices::AndroidRequestContextObserver::~AndroidRequestContextObserver() {
	auto func = (void(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZN20androidstoreservices29AndroidRequestContextObserverD1Ev");
	func(handle.get());
}
