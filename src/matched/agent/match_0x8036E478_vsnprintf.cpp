// 0x8036E478 vsnprintf (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 30,0x68(1); stw 0,0x74(1); mr 30,4; lwz 11,-27948(13); mr 9,3; li 0,520; mr 4,5; stw 9,0x18(1); sth 0,0x14(1); mr 5,6; stw 9,0x8(1); addi 3,1,8; stw 11,0x64(1); stw 30,0x10(1); stw 30,0x1c(1); bl _s8036E478_0; lwz 9,0x8(1); li 0,0; cmplw 3,30; stb 0,0x0(9); ble 0f; li 3,-1; 0:; lwz 0,0x74(1); mtspr 8,0; lmw 30,0x68(1); addi 1,1,112"
extern "C" void _s8036E478_0();
extern "C" void f_8036E478() {}
