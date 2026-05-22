// 0x80042358 EGlobal::IsPlayerCheatOn(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x400(3); cmpwi 0,0; beq 0f; li 3,1; blr; 0:; lhz 0,0x9c(3); li 3,0; sraw 0,0,4; andi. 9,0,1; beqlr; li 3,1"
extern "C" int f_80042358() {}
