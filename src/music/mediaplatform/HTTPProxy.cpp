//
// Created by dadoum on 13/05/2021.
//

#include "music/mediaplatform/HTTPProxy.hpp"

mediaplatform::HTTPProxy::HTTPProxy(std::shared_ptr<void> h) {
	handle = h;
}

mediaplatform::HTTPProxy::HTTPProxy(int type, std::string const& ip, unsigned short const& port) {
	handle = std::make_shared<void*>();
	auto func = (void(*)(void* nativeObject, int type, std::string const& ip, unsigned short const& port)) LIBRARY->loadSymbol("_ZN13mediaplatform9HTTPProxyC2ENS0_4TypeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKt");
	func(handle.get(), type, ip, port);
}
