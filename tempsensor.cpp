/*******************************************************************
*
*  DESCRIPTION: class Temperature Generator
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

/** include files **/
#include "tempsensor.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator
#include "distri.h"        // class Distribution 
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: TempSensor
* Description: constructor
********************************************************************/
TempSensor::TempSensor( const string &name )
: Atomic( name )
, Troom( addOutputPort( "Troom" ) )
, HeatLosses( addInputPort( "HeatLosses" ) )
, HeatGain(addInputPort("HeatGain"))
{
 string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
 if( time != "" )
 preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &TempSensor::initFunction()
{
	RoomTemp = 25.0;   // initial temp = 25 degrees Celsius
	HeatG = 0.0;
	HeatLoss = 0.0;
	holdIn( active, Time::Zero );
	return *this ;
	
}
/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &TempSensor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == HeatLosses )
	this->HeatLoss = static_cast<float>(msg.value());
	if( msg.port() == HeatGain )
	this->HeatG = static_cast<float>(msg.value());
	this->RoomTemp = RoomTemp + HeatG - HeatLoss;
	HeatLoss = 0.0;
	HeatG = 0.0;
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &TempSensor::internalFunction( const InternalMessage & )
{
	holdIn(active, preparationTime );
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &TempSensor::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), Troom, RoomTemp ) ;
	//sendOutput( msg.time(), Troom, Report ); 
	return *this ;
}

TempSensor::~TempSensor()
{
	delete dist;
}