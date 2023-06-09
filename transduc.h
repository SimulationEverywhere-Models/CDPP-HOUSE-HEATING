/*******************************************************************
*
*  DESCRIPTION: class Transducer
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 12/10/2008
*
*******************************************************************/

#ifndef __TRANSDUC_H
#define __TRANSDUC_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException


/** declarations **/
class Transducer : public Atomic
{
public:
	Transducer( const string &name = "Transducer" );	// Default constructor

	~Transducer();

	virtual string className() const;
	

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &Tout, &Troom ;//input port Tout from generator; Troom is input from Indoor Temp Sensor;
	Port &HeatLosses;  //output port named Heat Losses
	float OutdoorTemp,IndoorTemp;
	float HeatLoss;  //float variable representing heat losses
	float K;  //constant value representing heat losses of a house
	Time preparationTime;
		
};	// class Transducer

// ** inline ** // 
inline
string Transducer::className() const
{
	return "Transducer" ;
}

#endif   //__TRANSDUC_H 
