/*******************************************************************
*
*  DESCRIPTION: class Controller
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

/** include files **/
#include "controller.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator
#include "distri.h"        // class Distribution 
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: TempSensor
* Description: constructor
********************************************************************/
Controller::Controller( const string &name )
: Atomic( name )
, Troom( addInputPort( "Troom" ) )
, HeaterCntrSignal( addOutputPort( "HeaterCntrSignal" ) )
{
 SetPoint = 25.0;   // initial temp = 25 degrees Celsius
 CntrSignal = 0;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Controller::initFunction()
{
	holdIn( active, Time::Zero );
	return *this ;
	
}
/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Controller::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == Troom )
	this->IndoorTemp = static_cast<float>(msg.value());
	///
	//IndoorTemp = 25.0;
	if(IndoorTemp <= (SetPoint-0.1)){
		CntrSignal = 1;
	}
	else{
		CntrSignal = 0;
	}
	holdIn(active, preparationTime );
	return *this ;
	
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Controller::internalFunction( const InternalMessage & )
{
	//IndoorTemp = 27.0;
//	if(IndoorTemp <= (SetPoint-0.1)){
//		CntrSignal = 1;
//	}
//	else{
//		CntrSignal = 0;
//	}
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Controller::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), HeaterCntrSignal, CntrSignal ) ;
	return *this ;
}

Controller::~Controller()
{
	delete dist;
}