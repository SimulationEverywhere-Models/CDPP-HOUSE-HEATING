/*******************************************************************
*
*  DESCRIPTION: class Transducer
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 12/10/2008
*
*******************************************************************/

/** include files **/
#include "transduc.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator

/*******************************************************************
* Function Name: Transducer
* Description: constructor
********************************************************************/
Transducer::Transducer( const string &name )
: Atomic( name )
, HeatLosses( addOutputPort( "HeatLosses" ))
, Tout( addInputPort( "Tout" ) )
, Troom( addInputPort( "Troom" ) ) 
{
string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Transducer::initFunction()
{
	K = 0.1;  //initiate value representing heat losses of a house	
	holdIn( active, Time::Zero );
	return *this ;
	
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Transducer::externalFunction( const ExternalMessage &msg )
{
	 
	if( msg.port() == Tout )
	this->OutdoorTemp = static_cast<float>(msg.value());
	if( msg.port() == Troom )
	this->IndoorTemp = static_cast<float>(msg.value());
	if (IndoorTemp > OutdoorTemp)
	{
		HeatLoss = fabs(IndoorTemp - OutdoorTemp);
		HeatLoss *=K;
	}
	else
	{
		HeatLoss = 0;
	}	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Transducer::internalFunction( const InternalMessage & )
{
	
	holdIn(active, preparationTime );
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Transducer::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), this->HeatLosses, this->HeatLoss ) ;
	return *this ;
}
Transducer::~Transducer()
{
	;
}
