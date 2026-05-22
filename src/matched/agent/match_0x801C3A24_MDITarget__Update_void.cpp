// 0x801C3A24 MDITarget::Update(void) (608 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); mr 29,3; lwz 0,0x90(29); cmpwi 0,0; beq 1f; lwz 0,0x98(29); cmpwi 0,0; bne 1f; lwz 0,0x9c(29); cmpwi 0,0; beq 0f; lwz 0,0x94(29); cmpwi 0,0; bne 1f; addi 3,1,8; lis 30,-32705; bl _s801C3A24_0; addi 3,1,8; addi 4,30,9568; li 5,1; li 6,0; bl _s801C3A24_1; lis 7,-32705; addi 3,1,8; addi 7,7,9528; li 5,250; li 6,0; li 8,0; addi 4,30,9568; bl _s801C3A24_2; li 4,255; addi 3,1,8; bl _s801C3A24_3; addi 3,1,8; bl _s801C3A24_4; li 0,1; addi 3,1,8; stw 0,0x94(29); li 4,2; stw 0,0x98(29); bl _s801C3A24_5; b 1f; 0:; lwz 0,0x94(29); cmpwi 0,0; beq 1f; addi 3,1,8; bl _s801C3A24_6; lis 4,-32705; lis 7,-32705; addi 3,1,8; addi 7,7,9548; li 5,250; li 6,0; li 8,0; addi 4,4,9568; bl _s801C3A24_7; li 4,0; addi 3,1,8; bl _s801C3A24_8; addi 3,1,8; bl _s801C3A24_9; li 0,1; addi 3,1,8; stw 0,0x98(29); li 4,2; bl _s801C3A24_10; 1:; lwz 0,0x84(29); cmpwi 0,0; beq 9f; lis 9,-32697; lwz 3,0x5f08(9); cmpwi 3,0; beq 2f; bl _s801C3A24_11; cmpwi 3,0; bne 10f; 2:; lwz 0,0x9c(29); cmpwi 0,0; beq 8f; lis 9,-32705; lfs f0,-26800(13); lfs f12,0x25c4(9); lwz 11,0x84(29); fmuls f0,f0,f12; lwz 0,0x1c(11); fctiwz f13,f0; stfd f13,0x28(1); lwz 9,0x2c(1); subf 0,9,0; stw 0,0x1c(11); lwz 30,0x84(29); lwz 0,0x1c(30); cmpwi 0,0; bge 10f; lwz 0,0x20(30); cmpwi 30,0; stw 0,0x84(29); beq 6f; lwz 31,0x8(30); cmpwi 31,0; beq 3f; mr 3,31; bl _s801C3A24_12; li 0,0; stw 0,0xc(30); stw 0,0x8(30); b 4f; 3:; lwz 4,0xc(30); cmpwi 4,0; beq 4f; lis 3,-32692; addi 3,3,-17444; bl _s801C3A24_13; stw 31,0xc(30); 4:; lwz 3,0x10(30); cmpwi 3,0; beq 5f; bl _s801C3A24_14; li 0,0; stw 0,0x10(30); 5:; addi 3,30,4; li 4,2; bl _s801C3A24_15; mr 3,30; li 4,2; bl _s801C3A24_16; mr 3,30; bl _s801C3A24_17; 6:; lwz 0,0x84(29); cmpwi 0,0; beq 7f; mr 3,29; bl _s801C3A24_18; b 10f; 7:; mr 3,29; bl _s801C3A24_19; b 10f; 8:; mr 3,29; bl _s801C3A24_20; mr 3,29; bl _s801C3A24_21; b 10f; 9:; mr 3,29; bl _s801C3A24_22; 10:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"
extern "C" void _s801C3A24_0();
extern "C" void _s801C3A24_1();
extern "C" void _s801C3A24_2();
extern "C" void _s801C3A24_3();
extern "C" void _s801C3A24_4();
extern "C" void _s801C3A24_5();
extern "C" void _s801C3A24_6();
extern "C" void _s801C3A24_7();
extern "C" void _s801C3A24_8();
extern "C" void _s801C3A24_9();
extern "C" void _s801C3A24_10();
extern "C" void _s801C3A24_11();
extern "C" void _s801C3A24_12();
extern "C" void _s801C3A24_13();
extern "C" void _s801C3A24_14();
extern "C" void _s801C3A24_15();
extern "C" void _s801C3A24_16();
extern "C" void _s801C3A24_17();
extern "C" void _s801C3A24_18();
extern "C" void _s801C3A24_19();
extern "C" void _s801C3A24_20();
extern "C" void _s801C3A24_21();
extern "C" void _s801C3A24_22();
extern "C" void f_801C3A24() {}
