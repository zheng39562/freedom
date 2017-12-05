/**********************************************************
 *  \file engine.cpp
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#include "engine.h"

#include <dlfcn.h>
#include "fr_public/pub_timer.h"

using namespace std;
using namespace fr_public;

namespace freedom
{

Engine::Engine()
	:dl_handle_(NULL),
	 server_(),
	 service_(NULL),
	 options_()
{
	;
}

Engine::~Engine(){
	Stop();
}

typedef google::protobuf::Service* (*CreateServerImplFunc)();

bool Engine::Run(const std::string& dll_name, const std::string& ip, int port){
	string lib_dll_name = "./lib" + dll_name + ".so";
	dl_handle_ = dlopen(lib_dll_name.c_str(), RTLD_NOW);
	if(dl_handle_ == NULL){
		DEBUG_E("Error : load dll [" << lib_dll_name << "] .");
		return false;
	}
	char* dl_error = dlerror(); 
	if(dl_error != NULL){
		DEBUG_E("Error : dlerror -> [" << dl_error << "]");
		return false;
	}

	CreateServerImplFunc create_server_impl_func = (CreateServerImplFunc)dlsym(dl_handle_, "CreateServerImpl");
	dl_error = dlerror(); 
	if(dl_error != NULL){
		DEBUG_E("Error : dlerror -> [" << dl_error << "]");
		DEBUG_E("Can not find Func(CreateServerImpl)");
		dlclose(dl_handle_);
		return false;
	}

	service_ = create_server_impl_func();
	if(service_ == NULL){
		DEBUG_D("add service... ");
		if(!server_.AddService(service_, brpc::SERVER_DOESNT_OWN_SERVICE)){
			DEBUG_E("Fail to add service.");
			return false;
		}

		string ip_port = ip + ":" + to_string(port);
		if(server_.Start(ip_port.c_str(), &options_) != 0){
			DEBUG_E("Fail to start server.");
			return false;
		}
	}

	return Stop();
}


bool Engine::Stop(){
	server_.RunUntilAskedToQuit();

	DEBUG_D("server is stopping.");

	if(service_ != NULL){
		delete service_;
		service_ = NULL;
	}

	if(dl_handle_ != NULL){
		dlclose(dl_handle_);
		dl_handle_ = NULL;
	}

	return true;
}

}// namespace freedom


