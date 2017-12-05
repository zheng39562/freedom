/**********************************************************
 *  \file main.cpp
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#include "engine.h"

#include "engine_define.h"
#include "engine.h"

using namespace std;
using namespace fr_public;
using namespace freedom;

enum eArgcIndex{
	eArgcIndex_Main = 0,
	eArgcIndex_DllName = 1,
	eArgcIndex_Ip = 2,
	eArgcIndex_Port = 3,
	eArgcIndex_LogDir = 4,
	eArgcIndex_LogLevel = 5,
	eArgcIndex_,
	eArgcIndex_End,
};

enum eMainReturnErrNo{
	eMainReturnErrNo_Ok = 0,
	eMainReturnErrNo_UndefinedParamemter,
	eMainReturnErrNo_CreateEngine,
	eMainReturnErrNo_RunParameterSize,
	eMainReturnErrNo_RunServer,
	eMainReturnErrNo_,
	eMainReturnErrNo_End,
};

/*
\param[in] argc 
\param[in] argv 
	* argv[0] : dll name. example: libworld.dll. its name is world. 
	* argv[1] : ip
	* argv[2] : port
	* argv[3] : log folder. allow empty. default : ./log. 
	* argv[4] : log level
*/
int main(int argc, char* argv[]){
	string dll_name("");
	string ip("0.0.0.0");
	int port(12345);
	string log_path("./log/");
	eLogLevel log_level(eLogLevel_Program);
	int max_file_size(10 * 1024 * 1024);

	if(argc < 4){
		DEBUG_E("The number(" << argc << ") of paremter is not enough.");
		return eMainReturnErrNo_RunParameterSize;
	}

	for(int index = 0; index < argc; ++index){
		string parameter(argv[index]);
		switch(index)
		{
			case eArgcIndex_Main:						break;
			case eArgcIndex_DllName:					dll_name = parameter; break;
			case eArgcIndex_Ip:							ip = parameter; break;
			case eArgcIndex_Port:						port = stoi(parameter); break;
			case eArgcIndex_LogDir:						log_path = string(parameter); break;
			case eArgcIndex_LogLevel:					log_level = PARSE_LOG_STRING(parameter); break;
			default: DEBUG_E("undefined parameter"); return eMainReturnErrNo_UndefinedParamemter;
		}
	}

	DEBUG_D("load dll [" << dll_name << "] log path [" << log_path << "] max size of file [" << max_file_size << "] ");
	SingleLogServer::GetInstance()->InitLog(log_path, max_file_size);
	SingleLogServer::GetInstance()->set_default_log_key(dll_name);
	SingleLogServer::GetInstance()->set_log_level(dll_name, log_level);

	DEBUG_I("Run Server : [" << dll_name << "] [" << ip << ":" << port << "]");

	Engine engine;
	if(!engine.Run(dll_name, ip, port)){
		DEBUG_E("run server failed.");
		return eMainReturnErrNo_RunServer;
	}

	return eMainReturnErrNo_Ok;
}

