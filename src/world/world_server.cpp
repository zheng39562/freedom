/**********************************************************
 *  \file world_server.cpp
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#include "world_server.h"

#include <brpc/server.h>
#include "fr_public/pub_timer.h"

using namespace fr_public;

google::protobuf::Service* CreateServerImpl(){
	return new freedom::world::WorldService();
}

namespace freedom{
namespace world{

WorldService::WorldService()
{ ; }

WorldService::~WorldService(){
	;
}

void WorldService::Echo(::google::protobuf::RpcController* controller, const ::freedom::world::Req* request, ::freedom::world::Res* response, ::google::protobuf::Closure* done){
	// This object helps you to call done->Run() in RAII style. If you need
	// to process the request asynchronously, pass done_guard.release().
	brpc::ClosureGuard done_guard(done);

	brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);

	// The purpose of following logs is to help you to understand
	// how clients interact with servers more intuitively. You should 
	// remove these logs in performance-sensitive servers.
	DEBUG_D("Received request[log_id=" << cntl->log_id() 
			  << "] from " << cntl->remote_side() 
			  << " to " << cntl->local_side()
			  << ": " << request->message()
			  << " (attached=" << cntl->request_attachment() << ")");

	// Fill response.
	response->set_message(request->message());

	// You can compress the response by setting Controller, but be aware
	// that compression may be costly, evaluate before turning on.
	// cntl->set_response_compress_type(brpc::COMPRESS_TYPE_GZIP);
}

} // namespace world{
} // namespace freedom{

