/*******************************************************************
*
*  DESCRIPTION: class Temperature Generator
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

#ifndef __TEMPSENSOR_H
#define __TEMPSENSOR_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** forward declarations **/
class Distribution ;

/** declarations **/
class TempSensor : public Atomic
{
public:
	TempSensor( const string &name = "TempSensor" );	// Default constructor

	~TempSensor();

	virtual string className() const
		{return "TempSensor";}

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &Troom;
    const Port &HeatLosses ;
    const Port &HeatGain;
	Distribution *dist ;
	float RoomTemp,HeatLoss,HeatG;
	Time preparationTime;
	Distribution &distribution()
	{return *dist;}
			
};	// class TempSensor


#endif   //__TEMPSENSOR_H 
