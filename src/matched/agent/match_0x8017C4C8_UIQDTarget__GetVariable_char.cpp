// 0x8017C4C8 UIQDTarget::GetVariable(char (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-424(1); mfspr 0,8; stmw 28,0x198(1); stw 0,0x1ac(1); mr 28,4; mr 3,28; bl _s8017C4C8_0; mr 29,3; cmpwi 29,6; ble 0f; cmpwi 28,0; bne 1f; 0:; li 3,0; b 15f; 1:; li 3,8192; addi 30,1,264; bl _s8017C4C8_1; li 0,0; mr 31,3; sth 0,0x0(31); li 7,0; stb 0,0x108(1); li 9,0; stb 0,0x8(1); li 8,0; stb 0,0x88(1); li 10,0; li 11,0; cmpw 7,29; bge 7f; addi 5,1,8; li 4,0; addi 6,1,136; mr 3,30; 2:; lbzx 0,28,7; cmpwi 0,58; bne 3f; addi 9,9,1; b 6f; 3:; cmpwi 9,1; bne 4f; stbx 0,5,11; addi 11,11,1; stbx 4,5,11; b 6f; 4:; cmpwi 9,2; bne 5f; stbx 0,6,10; addi 10,10,1; stbx 4,6,10; b 6f; 5:; cmpwi 9,3; bne 6f; stbx 0,3,8; addi 8,8,1; stbx 4,3,8; 6:; addi 7,7,1; cmpw 7,29; blt 2b; 7:; addi 3,1,8; bl _s8017C4C8_2; addi 3,1,8; bl _s8017C4C8_3; mr 3,30; bl _s8017C4C8_4; mr 3,30; bl _s8017C4C8_5; lis 3,-32706; addi 4,1,8; addi 3,3,12964; bl _s8017C4C8_6; cmpwi 3,0; bne 8f; lis 4,-32697; mr 5,30; addi 4,4,24012; addi 3,1,392; crxor 6,6,6; bl _s8017C4C8_7; lwz 9,0x188(1); b 10f; 8:; lis 3,-32706; addi 4,1,8; addi 3,3,12976; bl _s8017C4C8_8; cmpwi 3,0; bne 9f; lis 4,-32697; mr 5,30; addi 4,4,24012; addi 3,1,396; crxor 6,6,6; bl _s8017C4C8_9; lwz 9,0x18c(1); b 10f; 9:; lis 3,-32706; addi 4,1,8; addi 3,3,12992; bl _s8017C4C8_10; cmpwi 3,0; bne 12f; lis 4,-32697; mr 5,30; addi 4,4,24012; addi 3,1,400; crxor 6,6,6; bl _s8017C4C8_11; lwz 9,0x190(1); 10:; li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,31; bl _s8017C4C8_12; b 14f; 12:; lis 3,-32706; addi 4,1,8; addi 3,3,13004; bl _s8017C4C8_13; cmpwi 3,0; bne 14f; lis 4,-32697; mr 5,30; addi 4,4,24012; addi 3,1,404; crxor 6,6,6; bl _s8017C4C8_14; lwz 9,0x194(1); li 4,0; cmpwi 9,0; beq 13f; lwz 4,0x0(9); 13:; mr 3,31; bl _s8017C4C8_15; 14:; mr 3,31; bl _s8017C4C8_16; li 3,8192; bl _s8017C4C8_17; mr 30,3; mr 3,31; bl _s8017C4C8_18; addi 4,3,1; mr 5,30; mr 3,31; bl _s8017C4C8_19; mr 3,31; bl _s8017C4C8_20; mr 3,30; 15:; lwz 0,0x1ac(1); mtspr 8,0; lmw 28,0x198(1); addi 1,1,424"
extern "C" void _s8017C4C8_0();
extern "C" void _s8017C4C8_1();
extern "C" void _s8017C4C8_2();
extern "C" void _s8017C4C8_3();
extern "C" void _s8017C4C8_4();
extern "C" void _s8017C4C8_5();
extern "C" void _s8017C4C8_6();
extern "C" void _s8017C4C8_7();
extern "C" void _s8017C4C8_8();
extern "C" void _s8017C4C8_9();
extern "C" void _s8017C4C8_10();
extern "C" void _s8017C4C8_11();
extern "C" void _s8017C4C8_12();
extern "C" void _s8017C4C8_13();
extern "C" void _s8017C4C8_14();
extern "C" void _s8017C4C8_15();
extern "C" void _s8017C4C8_16();
extern "C" void _s8017C4C8_17();
extern "C" void _s8017C4C8_18();
extern "C" void _s8017C4C8_19();
extern "C" void _s8017C4C8_20();
extern "C" void f_8017C4C8() {}
