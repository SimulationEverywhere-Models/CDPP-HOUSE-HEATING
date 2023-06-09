[top]
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

