[top]
components : generat@Generator
components : transduc@Transducer 
components : Thermostat
components : heater@HouseHeater

out : Tout Troom HeaterCntrSignal HeatLosses HeatGain

Link : Tout@generat Tout
Link : Troom@Thermostat Troom
Link : HeatLosses@transduc HeatLosses
Link : HeatGain@heater HeatGain

Link : Tout@generat Tout@transduc 
Link : HeatLosses@transduc HeatLosses@Thermostat
Link : HeatGain@heater HeatGain@Thermostat 
Link : Troom@Thermostat Troom@transduc 
Link : Troom@Thermostat Troom@heater 
Link : HeaterCntrSignal@Thermostat HeaterCntrSignal@heater 
Link : HeaterCntrSignal@Thermostat HeaterCntrSignal

[generat] 
distribution : normal 
mean : 22 
deviation : 3 

[transduc] 
preparation : 00:00:01:000 

[heater] 
preparation : 00:00:01:000 

[Thermostat]
components : tempsensor@TempSensor
components : controller@Controller

in : HeatLosses HeatGain
out : Troom HeaterCntrSignal

Link : Troom@tempsensor Troom
Link : Troom@tempsensor Troom@controller
Link : HeatLosses HeatLosses@tempsensor
Link : HeatGain HeatGain@tempsensor
Link : HeaterCntrSignal@controller HeaterCntrSignal

[tempsensor]
preparation : 00:00:01:000

[controller]
preparation : 00:00:01:000