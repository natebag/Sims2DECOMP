// 0x80152FF0 XRoute::ClearCurrentGoal(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); cmpwi 9,-1; beqlr; cmpwi 9,0; blt 0f; lwz 0,0x4(3); lwz 11,0x0(3); subf 0,11,0; srawi 0,0,4; cmplw 9,0; bge 0f; rlwinm 9,9,4,0,27; li 0,0; add 9,11,9; stw 0,0x8(9); 0:; li 0,-1; stw 0,0x58(3); stw 0,0x54(3)"
extern "C" void f_80152FF0() {}
