// 0x8002BADC EIWallPart::GetPoints(CTilePt (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 31,5; bl _s8002BADC_0; lwz 0,0x320(30); li 9,1; andi. 11,0,48; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 6f; lwz 0,0x324(30); cmpwi 0,2; beq 4f; bgt 1f; cmpwi 0,1; beq 2f; b 13f; 1:; cmpwi 0,3; beq 3f; cmpwi 0,4; beq 5f; b 13f; 2:; addi 30,30,808; mr 3,30; bl _s8002BADC_1; addi 29,3,-1; mr 3,30; bl _s8002BADC_2; addi 5,3,1; b 11f; 3:; addi 30,30,808; mr 3,30; bl _s8002BADC_3; addi 29,3,1; b 10f; 4:; addi 30,30,808; mr 3,30; bl _s8002BADC_4; addi 29,3,1; mr 3,30; bl _s8002BADC_5; addi 5,3,1; b 11f; 5:; addi 30,30,808; mr 3,30; bl _s8002BADC_6; addi 29,3,-1; b 10f; 6:; cmpwi 0,2; beq 9f; bgt 7f; cmpwi 0,1; beq 12f; b 13f; 7:; cmpwi 0,4; beq 8f; cmpwi 0,8; bne 13f; addi 30,30,808; mr 3,30; bl _s8002BADC_7; mr 29,3; mr 3,30; bl _s8002BADC_8; addi 5,3,1; b 11f; 8:; addi 30,30,808; mr 3,30; bl _s8002BADC_9; addi 29,3,1; mr 3,30; bl _s8002BADC_10; mr 5,3; b 11f; 9:; addi 30,30,808; mr 3,30; bl _s8002BADC_11; mr 29,3; 10:; mr 3,30; bl _s8002BADC_12; addi 5,3,-1; 11:; mr 4,29; li 6,1; addi 3,1,8; bl _s8002BADC_13; addi 4,1,8; mr 3,31; bl _s8002BADC_14; addi 3,1,8; li 4,2; bl _s8002BADC_15; b 13f; 12:; addi 30,30,808; mr 3,30; bl _s8002BADC_16; addi 29,3,-1; mr 3,30; bl _s8002BADC_17; mr 5,3; mr 4,29; li 6,1; addi 3,1,8; bl _s8002BADC_18; addi 4,1,8; mr 3,31; bl _s8002BADC_19; addi 3,1,8; li 4,2; bl _s8002BADC_20; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8002BADC_0();
extern "C" void _s8002BADC_1();
extern "C" void _s8002BADC_2();
extern "C" void _s8002BADC_3();
extern "C" void _s8002BADC_4();
extern "C" void _s8002BADC_5();
extern "C" void _s8002BADC_6();
extern "C" void _s8002BADC_7();
extern "C" void _s8002BADC_8();
extern "C" void _s8002BADC_9();
extern "C" void _s8002BADC_10();
extern "C" void _s8002BADC_11();
extern "C" void _s8002BADC_12();
extern "C" void _s8002BADC_13();
extern "C" void _s8002BADC_14();
extern "C" void _s8002BADC_15();
extern "C" void _s8002BADC_16();
extern "C" void _s8002BADC_17();
extern "C" void _s8002BADC_18();
extern "C" void _s8002BADC_19();
extern "C" void _s8002BADC_20();
extern "C" void f_8002BADC() {}
