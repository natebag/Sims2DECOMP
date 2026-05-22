// 0x8017C72C UIQDTarget::GetQuickdataText(char (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-416(1); mfspr 0,8; stmw 30,0x198(1); stw 0,0x1a4(1); mr 30,3; bl _s8017C72C_0; cmpwi 3,6; ble 0f; cmpwi 30,0; bne 1f; 0:; li 3,0; b 14f; 1:; li 0,0; li 7,0; stb 0,0x108(1); li 9,0; stb 0,0x8(1); li 8,0; stb 0,0x88(1); li 10,0; li 11,0; cmpw 7,3; addi 31,1,264; bge 7f; addi 5,1,8; li 4,0; addi 6,1,136; mr 12,31; 2:; lbzx 0,30,7; cmpwi 0,58; bne 3f; addi 9,9,1; b 6f; 3:; cmpwi 9,1; bne 4f; stbx 0,5,11; addi 11,11,1; stbx 4,5,11; b 6f; 4:; cmpwi 9,2; bne 5f; stbx 0,6,10; addi 10,10,1; stbx 4,6,10; b 6f; 5:; cmpwi 9,3; bne 6f; stbx 0,12,8; addi 8,8,1; stbx 4,12,8; 6:; addi 7,7,1; cmpw 7,3; blt 2b; 7:; addi 3,1,8; li 30,0; bl _s8017C72C_1; addi 3,1,8; bl _s8017C72C_2; mr 3,31; bl _s8017C72C_3; mr 3,31; bl _s8017C72C_4; lis 3,-32706; addi 4,1,8; addi 3,3,12964; bl _s8017C72C_5; cmpwi 3,0; bne 8f; lis 4,-32697; addi 3,1,392; mr 5,31; addi 4,4,24012; crxor 6,6,6; bl _s8017C72C_6; lwz 9,0x188(1); b 11f; 8:; lis 3,-32706; addi 4,1,8; addi 3,3,12976; bl _s8017C72C_7; cmpwi 3,0; bne 9f; lis 4,-32697; addi 3,1,396; mr 5,31; addi 4,4,24012; crxor 6,6,6; bl _s8017C72C_8; lwz 9,0x18c(1); b 11f; 9:; lis 3,-32706; addi 4,1,8; addi 3,3,12992; bl _s8017C72C_9; cmpwi 3,0; bne 10f; lis 4,-32697; addi 3,1,400; mr 5,31; addi 4,4,24012; crxor 6,6,6; bl _s8017C72C_10; lwz 9,0x190(1); b 11f; 10:; lis 3,-32706; addi 4,1,8; addi 3,3,13004; bl _s8017C72C_11; cmpwi 3,0; bne 13f; lis 4,-32697; addi 3,1,404; mr 5,31; addi 4,4,24012; crxor 6,6,6; bl _s8017C72C_12; lwz 9,0x194(1); 11:; li 3,0; cmpwi 9,0; beq 12f; lwz 3,0x0(9); 12:; mr 30,3; 13:; mr 3,30; 14:; lwz 0,0x1a4(1); mtspr 8,0; lmw 30,0x198(1); addi 1,1,416"
extern "C" void _s8017C72C_0();
extern "C" void _s8017C72C_1();
extern "C" void _s8017C72C_2();
extern "C" void _s8017C72C_3();
extern "C" void _s8017C72C_4();
extern "C" void _s8017C72C_5();
extern "C" void _s8017C72C_6();
extern "C" void _s8017C72C_7();
extern "C" void _s8017C72C_8();
extern "C" void _s8017C72C_9();
extern "C" void _s8017C72C_10();
extern "C" void _s8017C72C_11();
extern "C" void _s8017C72C_12();
extern "C" void f_8017C72C() {}
