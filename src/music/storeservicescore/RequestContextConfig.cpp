//
// Created by dadoum on 13/05/2021.
//

#include "music/storeservicescore/RequestContextConfig.hpp"

void storeservicescore::RequestContextConfig::setHTTPProxy(mediaplatform::HTTPProxy const& httpProxy) {
	auto func = (void(*)(void* nativeObject, void*)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig12setHTTPProxyERKN13mediaplatform9HTTPProxyE");
	func(handle.get(), httpProxy.handle.get());
}

void storeservicescore::RequestContextConfig::setDeviceModel(std::string const& deviceModel) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig14setDeviceModelERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), deviceModel);
}

void storeservicescore::RequestContextConfig::setBuildVersion(std::string const& buildVersion) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig15setBuildVersionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), buildVersion);
}

void storeservicescore::RequestContextConfig::setContentBundle(std::shared_ptr<mediaplatform::ContentBundle> const& contentBundle) {
	auto func = (void(*)(void* nativeObject, std::shared_ptr<mediaplatform::ContentBundle> const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig16setContentBundleERKNSt6__ndk110shared_ptrIN13mediaplatform13ContentBundleEEE");
	func(handle.get(), contentBundle);
}

void storeservicescore::RequestContextConfig::setProductVersion(std::string const& productVersion) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig17setProductVersionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), productVersion);
}

void storeservicescore::RequestContextConfig::setResetHttpCache(bool resetHttpCache) {
	auto func = (void(*)(void* nativeObject, bool)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig17setResetHttpCacheEb");
	func(handle.get(), resetHttpCache);
}

void storeservicescore::RequestContextConfig::setClientIdentifier(std::string const& clientIdentifier) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig19setClientIdentifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), clientIdentifier);
}

void storeservicescore::RequestContextConfig::setLocaleIdentifier(std::string const& localeIdentifier) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig19setLocaleIdentifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), localeIdentifier);
}

void storeservicescore::RequestContextConfig::setBaseDirectoryPath(std::string const& baseDirectoryPath) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig20setBaseDirectoryPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), baseDirectoryPath);
}

void storeservicescore::RequestContextConfig::setVersionIdentifier(std::string const& versionIdentifier) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig20setVersionIdentifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), versionIdentifier);
}

void storeservicescore::RequestContextConfig::setLanguageIdentifier(std::string const& languageIdentifier) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig21setLanguageIdentifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), languageIdentifier);
}

void storeservicescore::RequestContextConfig::setPlatformIdentifier(std::string const& platformIdentifier) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig21setPlatformIdentifierERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), platformIdentifier);
}

void storeservicescore::RequestContextConfig::setFairPlayDirectoryPath(std::string const& fairPlayDirectoryPath) {
	auto func = (void(*)(void* nativeObject, std::string const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig24setFairPlayDirectoryPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE");
	func(handle.get(), fairPlayDirectoryPath);
}

void storeservicescore::RequestContextConfig::setRequestContextObserver(androidstoreservices::AndroidRequestContextObserver const& requestContextObserver) {
	auto func = (void(*)(void* nativeObject, std::shared_ptr<void> const&)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfig24setPresentationInterfaceERKNSt6__ndk110shared_ptrINS_21PresentationInterfaceEEE");
	func(handle.get(), requestContextObserver.handle);
}

storeservicescore::RequestContextConfig::RequestContextConfig() {
	handle = std::make_shared<void*>();
	auto func = (void(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfigC2Ev");
	func(handle.get());
}

storeservicescore::RequestContextConfig::~RequestContextConfig() {
	auto func = (void(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZN17storeservicescore20RequestContextConfigD2Ev");
	func(handle.get());
}

std::string storeservicescore::RequestContextConfig::deviceModel() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig11deviceModelEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::buildVersion() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig12buildVersionEv");
	return func(handle.get());
}

std::shared_ptr<mediaplatform::ContentBundle> storeservicescore::RequestContextConfig::contentBundle() const {
	auto func = (std::shared_ptr<mediaplatform::ContentBundle>(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig13contentBundleEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::productVersion() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig14productVersionEv");
	return func(handle.get());
}

bool storeservicescore::RequestContextConfig::resetHttpCache() const {
	auto func = (bool(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig14resetHttpCacheEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::clientIdentifier() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig16clientIdentifierEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::localeIdentifier() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig16localeIdentifierEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::baseDirectoryPath() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig17baseDirectoryPathEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::versionIdentifier() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig17versionIdentifierEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::languageIdentifier() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig18languageIdentifierEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::platformIdentifier() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig18platformIdentifierEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::fairPlayDirectoryPath() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig21fairPlayDirectoryPathEv");
	return func(handle.get());
}

std::shared_ptr<androidstoreservices::AndroidRequestContextObserver> storeservicescore::RequestContextConfig::requestContextObserver() const {
	auto func = (std::shared_ptr<androidstoreservices::AndroidRequestContextObserver>(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig21presentationInterfaceEv");
	return func(handle.get());
}

std::string storeservicescore::RequestContextConfig::userAgent() const {
	auto func = (std::string(*)(void* nativeObject)) LIBRARY->loadSymbol("_ZNK17storeservicescore20RequestContextConfig9userAgentEv");
	return func(handle.get());
}
