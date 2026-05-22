// 0x802AAF0C AptNativeHash::FirstAllocation(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 4,0x0(30); lwz 3,-23020(13); rlwinm 4,4,3,0,28; bl _s802AAF0C_0; lwz 5,0x0(30); mr 0,3; stw 0,0x4(30); rlwinm 5,5,3,0,28; li 4,0; bl _s802AAF0C_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802AAF0C_0();
extern "C" void _s802AAF0C_1();
extern "C" void f_802AAF0C() {}
