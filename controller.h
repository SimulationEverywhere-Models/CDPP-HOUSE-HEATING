/*******************************************************************
*
*  DESCRIPTION: class Controller
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

#ifndef __CONTROLLER_H
#define __CONTROLLER_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** forward declarations **/
class Distribution ;

/** declarations **/
class Controller : public Atomic
{
public:
	Controller( const string &name = "TempSensor" );	// Default constructor

	~Controller();

	virtual string className() const
		{return "Controller";}

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &Troom;
	Port &HeaterCntrSignal;
   	Distribution *dist ;
	float SetPoint,IndoorTemp;
	int CntrSignal;
	Time preparationTime;
	Distribution &distribution()
	{return *dist;}
			
};	// class Controller


#endif   //____CONTROLLER_H 
