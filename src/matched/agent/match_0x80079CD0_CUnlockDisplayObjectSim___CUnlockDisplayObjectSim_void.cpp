// 0x80079CD0 CUnlockDisplayObjectSim::~CUnlockDisplayObjectSim(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 11,0x8c(31); addi 9,9,-12936; li 29,0; mr 30,4; stw 9,0x84(31); cmpwi 11,0; stw 29,0x10(31); beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; stw 29,0x8c(31); 0:; mr 3,31; mr 4,30; bl _s80079CD0_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80079CD0_0();
extern "C" void f_80079CD0() {}
