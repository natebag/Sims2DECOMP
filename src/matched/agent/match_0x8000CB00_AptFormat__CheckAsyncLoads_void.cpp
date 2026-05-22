// 0x8000CB00 AptFormat::CheckAsyncLoads(void) (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stfd f31,0x70(1); stmw 26,0x58(1); stw 0,0x7c(1); mr 28,3; li 27,1; lwz 31,0x50(28); lis 30,-32692; b 1f; 0:; lwz 31,0x0(31); 1:; cmpwi 31,0; beq 2f; lwz 0,0x8(31); cmpwi 0,0; bne 0b; lwz 4,0xc(31); addi 3,30,6092; bl _s8000CB00_0; cmpwi 3,0; stw 3,0x8(31); bne 0b; li 27,0; 2:; cmpwi 27,0; beq 5f; lwz 31,0x50(28); cmpwi 31,0; beq 5f; lis 9,-32707; lis 11,-32698; lfs f31,-10532(9); addi 26,11,-21528; 3:; lwz 9,0x8(31); li 3,196; lwz 29,0x14(9); bl _s8000CB00_1; mr 30,3; bl _s8000CB00_2; stw 26,0x0(30); lis 4,-32707; stw 30,0x4(31); mr 6,29; addi 4,4,-10552; li 5,0; mr 3,30; bl _s8000CB00_3; lwz 3,0x4(31); lis 4,-32717; lwz 5,0x8(31); addi 4,4,-18888; bl _s8000CB00_4; lwz 3,0x4(31); li 5,0; lwz 4,-25156(13); bl _s8000CB00_5; addi 3,1,8; addi 4,31,28; bl _s8000CB00_6; lfs f1,0x28(31); addi 3,1,8; bl _s8000CB00_7; lfs f1,0x2c(31); addi 3,1,8; bl _s8000CB00_8; lfs f1,0x30(31); addi 3,1,8; bl _s8000CB00_9; addi 4,31,16; addi 3,1,8; bl _s8000CB00_10; lwz 3,0x4(31); addi 4,1,8; bl _s8000CB00_11; lfs f11,0x34(31); fcmpu 0,f11,f31; cror 3,2,1; bns 4f; lfs f0,0x38(31); lfs f13,0x3c(31); lfs f12,0x50(31); stfs f11,0x48(1); stfs f0,0x4c(1); stfs f13,0x50(1); stfs f12,0x54(1); lwz 3,0x4(31); bl _s8000CB00_12; mr. 3,3; beq 4f; lwz 9,0x88(3); lfs f13,0x48(1); addi 11,9,80; stfs f13,0x50(9); lfs f0,0x4c(1); stfs f0,0x4(11); lfs f13,0x50(1); stfs f13,0x8(11); lwz 9,0x88(3); lfs f13,0x48(1); addi 11,9,96; stfs f13,0x60(9); lfs f0,0x4c(1); stfs f0,0x4(11); lfs f13,0x50(1); stfs f13,0x8(11); lwz 9,0x88(3); lfs f13,0x48(1); addi 11,9,112; stfs f13,0x70(9); lfs f0,0x4c(1); stfs f0,0x4(11); lfs f13,0x50(1); stfs f13,0x8(11); lwz 9,0x88(3); lfs f13,0x48(1); addi 11,9,128; stfs f13,0x80(9); lfs f0,0x4c(1); stfs f0,0x4(11); lfs f13,0x50(1); stfs f13,0x8(11); 4:; lwz 3,0x4(31); li 4,4; li 5,0; bl _s8000CB00_13; lwz 31,0x0(31); cmpwi 31,0; bne 3b; 5:; stw 27,0x60(28); lwz 0,0x7c(1); mtspr 8,0; lmw 26,0x58(1); lfd f31,0x70(1); addi 1,1,120"
extern "C" void _s8000CB00_0();
extern "C" void _s8000CB00_1();
extern "C" void _s8000CB00_2();
extern "C" void _s8000CB00_3();
extern "C" void _s8000CB00_4();
extern "C" void _s8000CB00_5();
extern "C" void _s8000CB00_6();
extern "C" void _s8000CB00_7();
extern "C" void _s8000CB00_8();
extern "C" void _s8000CB00_9();
extern "C" void _s8000CB00_10();
extern "C" void _s8000CB00_11();
extern "C" void _s8000CB00_12();
extern "C" void _s8000CB00_13();
extern "C" void f_8000CB00() {}
