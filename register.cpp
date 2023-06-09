/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Blerim Qela 
*
*  DATE: 11/10/2008
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "generat.h"	// class Generator
#include "transduc.h"	// class Transducer
#include "tempsensor.h"	// class TempSensor
#include "controller.h" // class Controller
#include "heater.h"  	// class HouseHeater

void MainSimulator::registerNewAtomics()
{
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<HouseHeater>() , "HouseHeater" ) ;
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Controller>() , "Controller" ) ;
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TempSensor>() , "TempSensor" ) ;
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
}
