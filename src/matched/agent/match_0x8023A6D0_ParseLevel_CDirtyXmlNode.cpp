// 0x8023A6D0 _ParseLevel(CDirtyXmlNode (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; mr 3,30; bl _s8023A6D0_0; stw 3,0x10(31); cmpwi 3,0; ble 0f; rlwinm 3,3,2,0,29; bl _s8023A6D0_1; mr 0,3; lwz 4,0x10(31); mr 5,30; stw 0,0x1c(31); bl _s8023A6D0_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023A6D0_0();
extern "C" void _s8023A6D0_1();
extern "C" void _s8023A6D0_2();
extern "C" void f_8023A6D0() {}
