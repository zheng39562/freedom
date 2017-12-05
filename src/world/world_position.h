/**********************************************************
 *  \file world_position.h
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#ifndef _world_position_H
#define _world_position_H

namespace world{

	class PositionAttribute
	{
		public:
			PositionAttribute(Coordinate x, Coordinate y, Coordinate z);
			~PositionAttribute()=default;
		public:
			Coordinate x()const{ return x_; }
			Coordinate y()const{ return y_; }
			Coordinate z()const{ return z_; }

		private:
			Coordinate x_;
			Coordinate y_;
			Coordinate z_;
	};

	//! \brief	主大陆
	//! \note	初步设计内：大陆以一个整体存在。
	class Mainland{
		public:
			Mainland();
			~Mainland();
		private:
	};

} // world

#endif 

