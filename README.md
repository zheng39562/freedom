## 目录构成：
	* doc : 设计and需求文档。
	* src : source folder。

## 需要的三方库
	* commmon :
		* link : @github.com:zheng39562/common.git
		* fr_sql : mysqlcppconn自行封装的简易接口
		* fr_public : 自己惯用的一些函数集合
	* mysqlcppconn : mysql的支持库
	* boost : filesystem, regex
	* rapidjson : 腾讯开源json库。无需编译
	* brpc : 百度的rpc
	* uuid : from yum or apt-get
	* other : 一些系统相关的库，可使用yum or apt-get 来解决
	* 几乎所有库的是可直接在github上找到的。所以就不贴链接了.

## make command
	* make all : 编译对应的功能.
	* make example : 生成对应的demo
	* make protoc : 生成新的protoc

## other
	* 联系方式：zheng39562@163.com


## todo
	* 请求的返回消息异步方案.
		* 如何将接口的多线程，和处理的单线程进行合并.
	* 通过链接发送消息.
	* 定时器的实现.

