// 0x8026BA40 CasTweakTool::~CasTweakTool(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026BA40_0; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40; blr; stw 3,-27592(13)"
extern "C" void _s8026BA40_0();
extern "C" void f_8026BA40() {}
