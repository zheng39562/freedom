/**********************************************************
 *  \file soil_entity.h
 *  \brief
 *  \note	注意事项： 
 * 
 * \version 
 * * \author zheng39562@163.com
**********************************************************/
#ifndef _soil_entity_H
#define _soil_entity_H

namespace world{
namespace base_world{
	typedef int CoordinateVar;
	typedef int MatterType;
	typedef int Energy;
	//! \brief	
	class SoilEntity{
		public:
			SoilEntity();
			~SoilEntity();
		public:
			inline CoordinateVar x()const{ return x_; }
			inline CoordinateVar y()const{ return y_; }
			inline MatterType matter_type()const{ return matter_type_; }
			inline Energy basic_energy()const{ return basic_energy_; }
		private:
			CoordinateVar x_;
			CoordinateVar y_;
			MatterType matter_type_;
			Energy basic_energy_;
	};

	class Land{
		public:
		private:
			Land* left; 
			Land* right; 
			Land* up; 
			Land* down; 
			vector<SoilEntity> 
	};
	// LangIdx;
}
}

#endif 

