/**********************************************************
 *  \file engine.h
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#ifndef _engine_H
#define _engine_H

#include "engine_define.h"

#include <google/protobuf/service.h>
#include <brpc/server.h>

#ifdef __LINUX
	#include <unistd.h>
	#include <sys/types.h>
	#include <signal.h>
#endif

// 无rpc的版本server: 启动，但没有对应的监听。所以基本也可以称为未完成版本.
//#define NO_RPC_ENGINE_SERVER_

namespace freedom{

//! \brief	
class Engine{
	public:
		Engine();
		virtual ~Engine();
	public:
		bool Run(const std::string& dll_name, const std::string& ip, int port);
	private:
		bool Stop();
	private:
		void* dl_handle_;		//! dll handle
		google::protobuf::Service* service_;	// 
		brpc::Server server_;
		brpc::ServerOptions options_;
};

} // namespace freedom

#endif 

