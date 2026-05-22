// 0x80255EBC OSUnlockMutex (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s80255EBC_0; mr 31,3; bl _s80255EBC_1; lwz 0,0x8(29); addi 30,3,0; cmplw 0,30; bne 5f; lwz 3,0xc(29); addic. 0,3,-1; stw 0,0xc(29); bne 5f; lwz 3,0x10(29); lwz 4,0x14(29); cmplwi 3,0; bne 0f; stw 4,0x2f8(30); b 1f; 0:; stw 4,0x14(3); 1:; cmplwi 4,0; bne 2f; stw 3,0x2f4(30); b 3f; 2:; stw 3,0x10(4); 3:; li 0,0; stw 0,0x8(29); lwz 3,0x2d0(30); lwz 0,0x2d4(30); cmpw 3,0; bge 4f; mr 3,30; bl _s80255EBC_2; stw 3,0x2d0(30); 4:; mr 3,29; bl _s80255EBC_3; 5:; mr 3,31; bl _s80255EBC_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80255EBC_0();
extern "C" void _s80255EBC_1();
extern "C" void _s80255EBC_2();
extern "C" void _s80255EBC_3();
extern "C" void _s80255EBC_4();
extern "C" void f_80255EBC() {}
