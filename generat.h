/*******************************************************************
*
*  DESCRIPTION: class Temperature Generator
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

#ifndef __GENERAT_H
#define __GENERAT_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** forward declarations **/
class Distribution ;

/** declarations **/
class Generator : public Atomic
{
public:
	Generator( const string &name = "Generator" );	// Default constructor

	~Generator();

	virtual string className() const
		{return "Generator";}

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & )
			{throw InvalidMessageException();}
	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	Port &Tout ;
	Distribution *dist ;
	float OutdoorTemp;
	float Tinit;  //initial outdoor temperature in degrees Celsius
	Distribution &distribution()
			{return *dist;}
			
};	// class Generator


#endif   //__GENERAT_H 
