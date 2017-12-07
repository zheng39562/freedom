#include "world_example.h"

#include <iostream>
#include <brpc/channel.h>

#include "world.pb.h"

using namespace std;

//! \note	12000
int main(int argc, char* argv[]){
	if(argc != 3){ cout << "error: parameter size " << argc << endl; return false; }

	string ip_and_port = string(argv[1]) + string(":") + string(argv[2]);
	cout << "ip and port : " << ip_and_port << endl;

    // A Channel represents a communication line to a Server. Notice that 
    // Channel is thread-safe and can be shared by all threads in your program.
    brpc::Channel channel;
    
    // Initialize the channel, NULL means using default options.
    brpc::ChannelOptions options;
    options.protocol = "baidu_std";
    options.connection_type = "";
    options.timeout_ms = 1000;
    options.max_retry = 3;
    if (channel.Init(ip_and_port.c_str(), "", &options) != 0) {
        cout << "Fail to initialize channel" << endl;
        return -1;
    }
	cout << "Init ip port success : " << ip_and_port << endl;

	freedom::world::Req req;
	freedom::world::Res res;
	req.set_message("hello world");

	brpc::Controller cntl;

    freedom::world::IWorldService_Stub stub(&channel);
	cout << "Call Echo ... " << endl;
	stub.Echo(&cntl, &req, &res, NULL);
	if (!cntl.Failed()) {
		cout << "Received response from " << cntl.remote_side()
			<< " to " << cntl.local_side()
			<< ": " << res.message() << " (attached="
			<< cntl.response_attachment() << ")"
			<< " latency=" << cntl.latency_us() << "us" << endl;
	} else {
		cout << cntl.ErrorText() << endl;
	}

	return 0;
}

