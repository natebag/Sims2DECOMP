// 0x801CA1E8 MODTarget::SetWarning(MODTarget::eSidePanelId, (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,5; lwz 0,0x84(31); mr 28,6; cmpwi 0,0; beq 10f; cmpwi 4,3; beq 1f; bgt 0f; cmpwi 4,2; beq 7f; b 10f; 0:; cmpwi 4,4; beq 3f; b 10f; 1:; lwz 0,0xb8(31); mr 9,0; cmpwi 0,0; bne 2f; cmpwi 30,0; beq 2f; addi 30,31,200; li 0,2; stw 0,0xb8(31); mr 3,30; bl _s801CA1E8_0; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12804; mr 3,30; bl _s801CA1E8_1; lis 4,-32705; mr 3,30; addi 4,4,3316; b 8f; 2:; cmpwi 9,2; bne 10f; cmpwi 30,0; bne 10f; stw 30,0xb8(31); addi 30,31,200; mr 3,30; bl _s801CA1E8_2; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12804; mr 3,30; bl _s801CA1E8_3; lis 4,-32705; mr 3,30; addi 4,4,12768; b 8f; 3:; mr 3,31; bl _s801CA1E8_4; lwz 9,0xbc(31); cmpwi 9,0; bne 6f; cmpwi 30,0; beq 6f; addi 30,31,200; li 0,2; stw 0,0xbc(31); mr 3,30; stw 9,0x9c(31); mr 29,30; bl _s801CA1E8_5; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12824; mr 3,30; bl _s801CA1E8_6; cmpwi 28,0; bne 4f; lis 4,-32705; mr 3,29; addi 4,4,3316; bl _s801CA1E8_7; b 5f; 4:; lis 4,-32705; mr 3,29; addi 4,4,12800; bl _s801CA1E8_8; 5:; mr 3,29; bl _s801CA1E8_9; b 10f; 6:; lwz 0,0xbc(31); cmpwi 0,2; bne 10f; cmpwi 30,0; bne 10f; stw 30,0xbc(31); addi 30,31,200; mr 3,30; bl _s801CA1E8_10; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12824; mr 3,30; bl _s801CA1E8_11; lis 4,-32705; mr 3,30; addi 4,4,12768; b 8f; 7:; lwz 0,0xb4(31); mr 9,0; cmpwi 0,0; bne 9f; cmpwi 30,0; beq 9f; addi 30,31,200; stw 4,0xb4(31); mr 3,30; bl _s801CA1E8_12; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12700; mr 3,30; bl _s801CA1E8_13; lis 4,-32705; mr 3,30; addi 4,4,12800; 8:; bl _s801CA1E8_14; mr 3,30; bl _s801CA1E8_15; b 10f; 9:; cmpwi 9,2; bne 10f; cmpwi 30,0; bne 10f; stw 30,0xb4(31); addi 30,31,200; mr 3,30; bl _s801CA1E8_16; lwz 5,0x94(31); lis 4,-32705; addi 4,4,12700; mr 3,30; bl _s801CA1E8_17; lis 4,-32705; mr 3,30; addi 4,4,12768; bl _s801CA1E8_18; mr 3,30; bl _s801CA1E8_19; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801CA1E8_0();
extern "C" void _s801CA1E8_1();
extern "C" void _s801CA1E8_2();
extern "C" void _s801CA1E8_3();
extern "C" void _s801CA1E8_4();
extern "C" void _s801CA1E8_5();
extern "C" void _s801CA1E8_6();
extern "C" void _s801CA1E8_7();
extern "C" void _s801CA1E8_8();
extern "C" void _s801CA1E8_9();
extern "C" void _s801CA1E8_10();
extern "C" void _s801CA1E8_11();
extern "C" void _s801CA1E8_12();
extern "C" void _s801CA1E8_13();
extern "C" void _s801CA1E8_14();
extern "C" void _s801CA1E8_15();
extern "C" void _s801CA1E8_16();
extern "C" void _s801CA1E8_17();
extern "C" void _s801CA1E8_18();
extern "C" void _s801CA1E8_19();
extern "C" void f_801CA1E8() {}
