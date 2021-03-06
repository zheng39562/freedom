/**********************************************************
 *  \!file login_impl.h
 *  \!brief
 *  \!note	注意事项： 
 * 			1,类中的成员函数中的同名参数的含义完全相同。仅会注释其中一个函数，其他函数则不再重复注释。重名的参数意义不同时，会独立注解。 
 * 			2,第1条的规则同样适用于返回值的含义。 
 * 
 * \!version 
 * * \!author zheng39562@163.com
**********************************************************/
#ifndef _login_impl_H
#define _login_impl_H

#include "fr_public/pub_define.h"

namespace FrLogin{
	//! \brief	
	//! \note	工作流程见work。登录器使用短连接（使用后马上断掉）
	//! \note	使用线程池。
	//! \note	登录服务器瞬间承压可能不会太好。但暂时没办法分担压力。
	class LoginImpl{
		public:
			LoginImpl();
			~LoginImpl();
		public:
			//! \brief	监听端口
			void listen(const string &ip, unsigned int port);
			void close();
		private:
			;
	};
	typedef 
}
#endif 

