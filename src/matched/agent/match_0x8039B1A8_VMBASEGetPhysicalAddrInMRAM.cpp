// 0x8039B1A8 VMBASEGetPhysicalAddrInMRAM (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s8039B1A8_0; lwz 0,0x4(3); rlwinm 3,0,0,4,19; addis 3,3,-32768; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B1A8_0();
extern "C" void f_8039B1A8() {}
