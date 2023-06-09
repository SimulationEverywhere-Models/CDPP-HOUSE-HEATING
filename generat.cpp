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
#include "generat.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator
#include "distri.h"        // class Distribution 
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: Generator
* Description: constructor
********************************************************************/
Generator::Generator( const string &name )
: Atomic( name )
, Tout( addOutputPort( "Tout" ) )
{
try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
		MASSERT( dist ) ;
		for ( register int i = 0; i < dist->varCount(); i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
			dist->setVar( i, str2Value( parameter ) ) ;
		}

	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Generator::initFunction()
{
	Tinit = 22.0;  //initial outdoor temperature 22 degrees Celsius
	OutdoorTemp = Tinit;
	holdIn( active, Time::Zero );
	return *this ;
	
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Generator::internalFunction( const InternalMessage & )
{
	//OutdoorTemp = gennor(Tinit,5.0);
	OutdoorTemp = fabs( distribution().get() );  // get Outdoor Temp for next time unit
	holdIn( active, Time( 0,0,1,0 )) ;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Generator::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), Tout, OutdoorTemp ) ;
	return *this ;
}

Generator::~Generator()
{
	delete dist;
}