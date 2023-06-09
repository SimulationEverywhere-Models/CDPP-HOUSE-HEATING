[top]
components : heater@HouseHeater

in : HeaterCntrSignal
in : Troom
out : HeatGain

Link : HeaterCntrSignal HeaterCntrSignal@heater 
Link : Troom Troom@heater
Link : HeatGain@heater HeatGain 


[heater]
preparation : 00:00:01:000
