// 0x80049A38 GetCircleSegmentClosedIX(EVec2 (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f31,0x58(1); stmw 25,0x3c(1); stw 0,0x64(1); mr 27,3; fmr f31,f1; mr 26,4; mr 28,5; mr 25,6; mr 30,7; bl _s80049A38_0; mr. 29,3; bne 9f; addi 31,1,8; mr 3,31; bl _s80049A38_1; addi 3,1,32; bl _s80049A38_2; mr 5,28; mr 3,27; fmr f1,f31; mr 4,26; mr 6,31; bl _s80049A38_3; cmpwi 3,0; beq 4f; lfs f13,0x10(30); lfs f0,0x10(31); fcmpu 0,f13,f0; ble 0f; lwz 8,0x10(31); li 7,1; lwz 0,0x8(1); lwz 9,0x4(31); lwz 11,0x8(31); lwz 10,0xc(31); stw 0,0x0(30); stw 9,0x4(30); stw 11,0x8(30); stw 10,0xc(30); stw 8,0x10(30); b 1f; 0:; li 7,0; 1:; cmpwi 29,0; li 0,1; bne 2f; li 0,0; 2:; cmpwi 7,0; li 3,1; bne 3f; li 3,0; 3:; or 29,0,3; 4:; mr 3,27; fmr f1,f31; mr 4,26; mr 5,25; addi 6,1,32; bl _s80049A38_4; cmpwi 3,0; beq 9f; lfs f13,0x10(30); lfs f0,0x30(1); fcmpu 0,f13,f0; ble 5f; lwz 9,0x20(1); li 7,1; lwz 11,0x24(1); lwz 10,0x28(1); lwz 8,0x2c(1); lwz 0,0x30(1); stw 9,0x0(30); stw 0,0x10(30); stw 11,0x4(30); stw 10,0x8(30); stw 8,0xc(30); b 6f; 5:; li 7,0; 6:; cmpwi 29,0; li 0,1; bne 7f; li 0,0; 7:; cmpwi 7,0; li 3,1; bne 8f; li 3,0; 8:; or 29,0,3; 9:; mr 3,29; lwz 0,0x64(1); mtspr 8,0; lmw 25,0x3c(1); lfd f31,0x58(1); addi 1,1,96"
extern "C" void _s80049A38_0();
extern "C" void _s80049A38_1();
extern "C" void _s80049A38_2();
extern "C" void _s80049A38_3();
extern "C" void _s80049A38_4();
extern "C" void f_80049A38() {}
