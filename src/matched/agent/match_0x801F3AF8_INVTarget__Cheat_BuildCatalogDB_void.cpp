// 0x801F3AF8 INVTarget::Cheat_BuildCatalogDB(void) (840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 28,0x18(1); stw 0,0x2c(1); stw 12,0x14(1); lwz 29,-21508(13); mr 28,3; li 4,0; li 30,0; lwz 9,0x0(29); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,29,3; blrl; mr 31,3; li 3,16; bl _s801F3AF8_0; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x15c(28); bl _s801F3AF8_1; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x158(28); bl _s801F3AF8_2; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x148(28); bl _s801F3AF8_3; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x14c(28); bl _s801F3AF8_4; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x150(28); bl _s801F3AF8_5; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x160(28); bl _s801F3AF8_6; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x154(28); bl _s801F3AF8_7; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x140(28); bl _s801F3AF8_8; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x144(28); bl _s801F3AF8_9; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x164(28); bl _s801F3AF8_10; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x168(28); bl _s801F3AF8_11; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x16c(28); bl _s801F3AF8_12; mr 9,3; stw 30,0x0(9); addi 11,9,8; stw 30,0x4(9); li 3,16; stw 30,0x4(11); stw 9,0x170(28); bl _s801F3AF8_13; stw 30,0x0(3); addi 9,3,8; stw 30,0x4(3); cmpwi 31,0; stw 30,0x4(9); stw 3,0x174(28); beq 3f; 0:; lwz 9,0x38(31); mr 4,31; mr 3,28; lha 0,0x14(9); cmpwi 0,0; beq 1f; lha 0,0x16(9); cmpwi 0,-1; bne 2f; 1:; bl _s801F3AF8_14; 2:; lwz 9,0x0(29); mr 4,31; lha 3,0x70(9); lwz 0,0x74(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; bne 0b; 3:; lis 11,-32697; li 31,0; lwz 9,0x5ea0(11); lwz 29,0x0(9); cmpwi 4,29,0; mr 30,29; b 5f; 4:; lwz 4,0x0(30); addi 30,30,4; bl _s801F3AF8_15; 5:; mr 5,31; mr 3,28; li 0,0; beq cr4,6f; lwz 0,-4(29); 6:; cmpw 31,0; addi 31,31,1; blt 4b; lis 9,-32697; li 31,0; lwz 29,0x5ea4(9); li 30,0; b 8f; 7:; lwzx 4,9,30; addi 30,30,4; bl _s801F3AF8_16; 8:; lwz 9,0x0(29); mr 5,31; mr 3,28; li 0,0; cmpwi 9,0; beq 9f; lwz 0,-4(9); 9:; cmpw 31,0; addi 31,31,1; blt 7b; lis 9,-32697; li 31,0; lwz 29,0x5ea8(9); li 30,0; b 11f; 10:; lwzx 4,9,30; addi 30,30,4; bl _s801F3AF8_17; 11:; lwz 9,0x0(29); mr 5,31; mr 3,28; li 0,0; cmpwi 9,0; beq 12f; lwz 0,-4(9); 12:; cmpw 31,0; addi 31,31,1; blt 10b; lwz 0,0x2c(1); lwz 12,0x14(1); mtspr 8,0; lmw 28,0x18(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s801F3AF8_0();
extern "C" void _s801F3AF8_1();
extern "C" void _s801F3AF8_2();
extern "C" void _s801F3AF8_3();
extern "C" void _s801F3AF8_4();
extern "C" void _s801F3AF8_5();
extern "C" void _s801F3AF8_6();
extern "C" void _s801F3AF8_7();
extern "C" void _s801F3AF8_8();
extern "C" void _s801F3AF8_9();
extern "C" void _s801F3AF8_10();
extern "C" void _s801F3AF8_11();
extern "C" void _s801F3AF8_12();
extern "C" void _s801F3AF8_13();
extern "C" void _s801F3AF8_14();
extern "C" void _s801F3AF8_15();
extern "C" void _s801F3AF8_16();
extern "C" void _s801F3AF8_17();
extern "C" void f_801F3AF8() {}
