/*******************************************************************
*
*  DESCRIPTION: class HouseHeater
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 12/10/2008
*
*******************************************************************/

/** include files **/
#include "heater.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator

/*******************************************************************
* Function Name: HouseHeater
* Description: constructor
********************************************************************/
HouseHeater::HouseHeater( const string &name )
: Atomic( name )
, HeatGain( addOutputPort( "HeatGain" ))
, HeaterCntrSignal( addInputPort( "HeaterCntrSignal" ) )
, Troom( addInputPort( "Troom" ) ) 
{
string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &HouseHeater::initFunction()
{
	Switch = 0;  //initiate value representing open relay switch position	
	Heat = 0.0;
	holdIn( active, Time::Zero );
	return *this ;
	
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &HouseHeater::externalFunction( const ExternalMessage &msg )
{
	 
	if( msg.port() == Troom )
	this->IndoorTemp = static_cast<float>(msg.value());
	if( msg.port() == HeaterCntrSignal)
	this->Switch = static_cast<int>(msg.value());
	if (Switch==true)
	{
		Heat = 0.5;
	}
	else
	{
		Heat = 0.0;	
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &HouseHeater::internalFunction( const InternalMessage & )
{
	
	holdIn(active, preparationTime );
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &HouseHeater::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), this->HeatGain, this->Heat ) ;
	return *this ;
}
HouseHeater::~HouseHeater()
{
	;
}
