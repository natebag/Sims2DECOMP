// 0x802998BC AptDisplayListState::insert(int, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 4,6; bl _s802998BC_0; mr 9,3; lwz 0,0x58(9); rlwimi 0,30,15,0,16; stw 0,0x58(9); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802998BC_0();
extern "C" void f_802998BC() {}
