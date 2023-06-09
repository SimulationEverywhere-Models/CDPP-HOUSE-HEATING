[top]
components : tempsensor@TempSensor

in : HeatLosses
in : HeatGain
out : Troom

Link : Troom@tempsensor Troom
Link : HeatLosses HeatLosses@tempsensor
Link : HeatGain HeatGain@tempsensor
 
[tempsensor]
preparation : 00:00:01:000