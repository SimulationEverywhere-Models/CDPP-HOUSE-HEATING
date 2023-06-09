/*******************************************************************
*
*  DESCRIPTION: class HouseHeater
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 12/10/2008
*
*******************************************************************/

#ifndef __HEATER_H
#define __HEATER_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** declarations **/
class HouseHeater : public Atomic
{
public:
	HouseHeater( const string &name = "Transducer" );	// Default constructor

	~HouseHeater();

	virtual string className() const;
	

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	//Troom is input from Indoor Temp Sensor;HeaterCntrSignal is input from Controller
	const Port &Troom,&HeaterCntrSignal ;
	Port &HeatGain;  //output port named HeatGain
	float Heat, IndoorTemp;
	int Switch;
	Time preparationTime;
		
};	// class HouseHeater

// ** inline ** // 
inline
string HouseHeater::className() const
{
	return "HouseHeater" ;
}

#endif   //__HEATER_H 
