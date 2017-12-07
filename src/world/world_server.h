/**********************************************************
 *  \file world_server.h
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#ifndef _world_server_H
#define _world_server_H

#include "world_define.h"
#include "world.pb.h"

extern "C"{
	google::protobuf::Service* CreateServerImpl();
}

namespace freedom{
namespace world{

class WorldService : public IWorldService{
	public:
		WorldService();
		virtual ~WorldService();
	public:
		virtual void Echo(::google::protobuf::RpcController* controller, const ::freedom::world::Req* request, ::freedom::world::Res* response, ::google::protobuf::Closure* done);
	private:
};

} // namespace world
} // namespace freedom

#endif 

