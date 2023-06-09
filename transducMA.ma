[top]
components : transduc@Transducer

in : Tout
in : Troom
out : HeatLosses

Link : HeatLosses@transduc HeatLosses
Link : Tout Tout@transduc
Link : Troom Troom@transduc

[transduc]
preparation : 00:00:01:000
