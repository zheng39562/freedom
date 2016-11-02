/**********************************************************
 *  \!file login_work.h
 *  \!brief
 *  \!note	注意事项： 
 * 			1,类中的成员函数中的同名参数的含义完全相同。仅会注释其中一个函数，其他函数则不再重复注释。重名的参数意义不同时，会独立注解。 
 * 			2,第1条的规则同样适用于返回值的含义。 
 * 
 * \!version 
 * * \!author zheng39562@163.com
**********************************************************/
#ifndef _login_work_H
#define _login_work_H

#include "fr_public/pub_define.h"
#include "fr_public/pub_thread.h"

namespace FrLogin{
	//! \brief	
	//! \note	工作流程：
	//				* 监听登录端口
	//				* 客户端连接请求。
	//				* 成功后，直接通过线程查询和验证帐号密码。
	//				* 验证成功后，打包客户端需要的信息发送给客户端。
	//				* 发送成功后，登录服务器主动断开链接。
	//				* 后续需要客户端主动去连接对应的网关服务器。
	class LoginWorker : public FCThread{

	};
}

#endif 

