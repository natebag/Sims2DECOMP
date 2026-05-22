// 0x80149B5C _Deque_base<StateMachineStatus (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,0,31,31; blr; lhz 0,0x110(3); cmpwi 4,0; rlwinm 0,0,0,0,30; sth 0,0x110(3); beqlr; ori 0,0,1; sth 0,0x110(3); blr; lhz 3,0x110(3); rlwinm 3,3,31,31,31; blr; lhz 0,0x110(3); cmpwi 4,0; rlwinm 0,0,0,31,29; sth 0,0x110(3); beqlr; ori 0,0,2; sth 0,0x110(3)"
extern "C" void f_80149B5C() {}
