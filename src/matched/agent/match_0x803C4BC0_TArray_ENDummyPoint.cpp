// 0x803C4BC0 TArray<ENDummyPoint, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 4,0x4(30); li 5,0; bl _s803C4BC0_0; lwz 3,0x0(29); lwz 5,0x4(30); lwz 4,0x0(30); bl _s803C4BC0_1; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C4BC0_0();
extern "C" void _s803C4BC0_1();
extern "C" void f_803C4BC0() {}
