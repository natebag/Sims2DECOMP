// 0x801F9BC8 KEYTarget::GetVariable(char (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,3; mr 30,4; li 3,32; bl _s801F9BC8_0; mr 31,3; li 0,0; lis 3,-32704; stb 0,0x0(31); addi 3,3,-22592; mr 4,30; bl _s801F9BC8_1; cmpwi 3,0; bne 0f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 3f; 0:; lis 3,-32704; mr 4,30; addi 3,3,-22564; bl _s801F9BC8_2; cmpwi 3,0; bne 1f; lis 5,-32704; mr 3,31; addi 5,5,-30836; li 4,32; li 6,0; crxor 6,6,6; bl _s801F9BC8_3; b 3f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-22580; bl _s801F9BC8_4; cmpwi 3,0; bne 3f; mr 3,29; bl _s801F9BC8_5; cmpwi 3,0; beq 3f; mr 3,29; bl _s801F9BC8_6; mr 29,3; bl _s801F9BC8_7; lis 30,-32697; lis 9,-32704; lis 11,-32704; addi 30,30,24012; mr 28,3; lfs f1,-22260(9); lfs f2,-22256(11); li 4,1; lwz 3,0x104(30); bl _s801F9BC8_8; lwz 4,0x104(30); mr 5,29; addi 3,1,16; li 6,1; li 7,0; li 8,0; bl _s801F9BC8_9; lwz 11,0x10(1); lis 9,-32704; lfs f13,-22252(9); stw 11,0x8(1); lwz 0,0x14(1); lfs f0,0x8(1); stw 0,0xc(1); fcmpu 0,f0,f13; ble 2f; li 28,15; 2:; lis 5,-32704; mr 6,28; addi 5,5,-30836; mr 3,31; li 4,32; crxor 6,6,6; bl _s801F9BC8_10; 3:; li 0,0; mr 3,31; stb 0,0x1f(31); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801F9BC8_0();
extern "C" void _s801F9BC8_1();
extern "C" void _s801F9BC8_2();
extern "C" void _s801F9BC8_3();
extern "C" void _s801F9BC8_4();
extern "C" void _s801F9BC8_5();
extern "C" void _s801F9BC8_6();
extern "C" void _s801F9BC8_7();
extern "C" void _s801F9BC8_8();
extern "C" void _s801F9BC8_9();
extern "C" void _s801F9BC8_10();
extern "C" void f_801F9BC8() {}
