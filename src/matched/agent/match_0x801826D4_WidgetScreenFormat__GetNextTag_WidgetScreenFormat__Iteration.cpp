// 0x801826D4 WidgetScreenFormat::GetNextTag(WidgetScreenFormat::IterationType) (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; li 28,0; b 10f; 0:; lwz 9,0x4(31); cmpwi 29,2; lwz 3,0x0(9); stw 3,0x8(31); bne 3f; bl _s801826D4_0; lwz 0,0xc(31); lis 4,-32705; addi 4,4,-24024; add 0,0,3; lwz 3,0x18(31); stw 0,0xc(31); bl _s801826D4_1; cmpwi 3,0; bne 1f; lwz 3,0x8(31); lis 4,-32705; addi 4,4,-24012; li 5,7; bl _s801826D4_2; cmpwi 3,0; bne 9f; b 2f; 1:; lwz 4,0x18(31); mr 3,31; bl _s801826D4_3; cmpwi 3,0; beq 9f; 2:; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); b 9f; 3:; cmpwi 29,3; bne 9f; lwz 3,0x18(31); lis 4,-32705; addi 4,4,-24004; bl _s801826D4_4; cmpwi 3,0; bne 4f; lis 9,-32705; lwz 11,0x14(31); lhz 0,-23992(9); sth 0,0x0(11); lwz 9,0x14(31); addi 9,9,1; stw 9,0x14(31); b 9f; 4:; lwz 3,0x18(31); lis 4,-32705; addi 4,4,-24024; bl _s801826D4_5; cmpwi 3,0; bne 5f; lwz 3,0x8(31); lis 30,-32705; addi 4,30,-24012; li 5,7; bl _s801826D4_6; cmpwi 3,0; bne 6f; addi 11,30,-24012; lwz 8,-24012(30); lwz 0,0x4(11); lwz 9,0x14(31); stw 0,0x4(9); stw 8,0x0(9); lwz 10,0x14(31); lbz 9,0x1f(31); addi 0,10,7; stw 0,0x14(31); addi 9,9,48; stb 9,0x7(10); lwz 11,0x14(31); lwz 4,0x8(31); addi 11,11,1; addi 4,4,7; mr 3,11; stw 11,0x14(31); bl _s801826D4_7; lwz 3,0x8(31); bl _s801826D4_8; lwz 0,0x14(31); addi 3,3,-7; b 8f; 5:; lwz 4,0x18(31); mr 3,31; bl _s801826D4_9; cmpwi 3,0; beq 6f; lbz 9,0x1f(31); lwz 10,0x14(31); addi 9,9,48; stb 9,0x0(10); lwz 11,0x14(31); lwz 4,0x8(31); addi 11,11,1; mr 3,11; stw 11,0x14(31); b 7f; 6:; lwz 4,0x8(31); lwz 3,0x14(31); 7:; bl _s801826D4_10; lwz 3,0x8(31); bl _s801826D4_11; lwz 0,0x14(31); 8:; add 0,0,3; stw 0,0x14(31); 9:; lwz 9,0x4(31); addi 28,28,1; addi 9,9,4; stw 9,0x4(31); 10:; lwz 9,0x4(31); lis 4,-32705; addi 4,4,-24028; li 5,1; lwz 3,0x0(9); bl _s801826D4_12; cmpwi 7,28,1; cmpwi 3,0; beq 11f; ble cr7,0b; 11:; ble cr7,12f; li 0,2; stw 0,0x0(31); 12:; lwz 9,0x4(31); lwz 3,0x0(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801826D4_0();
extern "C" void _s801826D4_1();
extern "C" void _s801826D4_2();
extern "C" void _s801826D4_3();
extern "C" void _s801826D4_4();
extern "C" void _s801826D4_5();
extern "C" void _s801826D4_6();
extern "C" void _s801826D4_7();
extern "C" void _s801826D4_8();
extern "C" void _s801826D4_9();
extern "C" void _s801826D4_10();
extern "C" void _s801826D4_11();
extern "C" void _s801826D4_12();
extern "C" void f_801826D4() {}
