// 0x801824D8 WidgetScreenFormat::IterateTags(WidgetScreenFormat::IterationType) (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 24,0x30(1); stw 0,0x54(1); stw 12,0x2c(1); mr 31,3; mr 30,4; bl _s801824D8_0; mr 28,3; mr 3,31; mr 4,28; bl _s801824D8_1; mr 29,28; cmpwi 3,0; beq 2f; cmpwi 3,30,2; bne cr3,0f; mr 3,28; bl _s801824D8_2; lwz 0,0xc(31); add 0,0,3; stw 0,0xc(31); b 1f; 0:; cmpwi 30,3; bne 1f; lwz 3,0x14(31); mr 4,28; bl _s801824D8_3; mr 3,28; bl _s801824D8_4; lwz 0,0x14(31); add 0,0,3; stw 0,0x14(31); 1:; lwz 9,0x4(31); lis 27,-32705; addi 4,27,-24040; li 5,2; addi 0,9,4; stw 0,0x4(31); lwz 3,0x4(9); bl _s801824D8_5; cmpwi 3,0; bne 4f; 2:; li 0,2; stw 0,0x0(31); b 10f; 3:; li 0,1; stw 0,0x0(31); b 10f; 4:; lhz 0,-24040(27); addi 9,27,-24040; lbz 10,0x2(9); addi 11,1,8; sth 0,0x8(1); mr 3,11; stb 10,0x2(11); addi 4,28,1; bl _s801824D8_6; cmpwi 30,3; lis 26,-32705; mfcr 27; lis 25,-32705; cmpwi 4,30,1; li 24,2; 5:; lwz 0,0x0(31); cmpwi 0,2; beq 10f; stw 29,0x18(31); mr 4,30; mr 3,31; bl _s801824D8_7; mr 29,3; addi 3,1,8; mr 4,29; bl _s801824D8_8; cmpwi 3,0; bne 9f; mtcrf 128,27; bne 6f; lwz 3,0x14(31); addi 4,1,8; bl _s801824D8_9; mr 3,29; bl _s801824D8_10; lwz 0,0x14(31); add 0,0,3; stw 0,0x14(31); b 8f; 6:; bne cr3,7f; addi 3,1,8; bl _s801824D8_11; lwz 0,0xc(31); add 0,0,3; stw 0,0xc(31); b 8f; 7:; bne cr4,8f; mr 4,28; mr 3,31; bl _s801824D8_12; 8:; addi 4,26,-24036; addi 3,1,8; bl _s801824D8_13; cmpwi 3,0; beq 3b; lwz 9,0x4(31); addi 4,25,-24028; li 5,1; addi 0,9,4; stw 0,0x4(31); lwz 3,0x4(9); bl _s801824D8_14; cmpwi 3,0; beq 10f; stw 24,0x0(31); b 10f; 9:; mr 3,31; mr 4,30; bl _s801824D8_15; b 5b; 10:; lwz 0,0x54(1); lwz 12,0x2c(1); mtspr 8,0; lmw 24,0x30(1); mtcrf 24,12; addi 1,1,80"
extern "C" void _s801824D8_0();
extern "C" void _s801824D8_1();
extern "C" void _s801824D8_2();
extern "C" void _s801824D8_3();
extern "C" void _s801824D8_4();
extern "C" void _s801824D8_5();
extern "C" void _s801824D8_6();
extern "C" void _s801824D8_7();
extern "C" void _s801824D8_8();
extern "C" void _s801824D8_9();
extern "C" void _s801824D8_10();
extern "C" void _s801824D8_11();
extern "C" void _s801824D8_12();
extern "C" void _s801824D8_13();
extern "C" void _s801824D8_14();
extern "C" void _s801824D8_15();
extern "C" void f_801824D8() {}
