// 0x80094B8C MorphUtilities::MorphLatticeOnHead(unsigned (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 30,3; beq 0f; mr 3,30; bl _s80094B8C_0; lha 30,0x4(30); lis 3,-32706; addi 3,3,-31376; mr 4,30; bl _s80094B8C_1; mr 3,31; mr 4,30; li 5,0; bl _s80094B8C_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80094B8C_3; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 1f; lwz 0,0x28(31); cmpwi 0,0; beq 1f; li 9,1; 1:; cmpwi 9,0; beq 2f; mr 3,31; li 4,2; bl _s80094B8C_4; b 4f; 2:; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 3f; lwz 0,0x2c(31); cmpwi 0,0; beq 3f; li 9,1; 3:; cmpwi 9,0; beq 4f; mr 3,31; li 4,1; bl _s80094B8C_5; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80094B8C_6; lis 9,-32697; lis 3,-32697; lwz 4,0x6214(9); addi 3,3,23428; bl _s80094B8C_7; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80094B8C_8; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 5f; lwz 0,0x28(31); cmpwi 0,0; beq 5f; li 9,1; 5:; cmpwi 9,0; bne 7f; lwz 0,0x20(31); li 9,0; cmpwi 0,0; bne 6f; lwz 0,0x2c(31); cmpwi 0,0; beq 6f; li 9,1; 6:; cmpwi 9,0; beq 12f; 7:; bl _s80094B8C_9; cmpwi 3,0; bne 8f; li 3,2; bl _s80094B8C_10; b 12f; 8:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 12f; lwz 0,0x20(31); li 11,0; mr 9,0; cmpwi 0,0; bne 9f; lwz 0,0x28(31); cmpwi 0,0; beq 9f; li 11,1; 9:; cmpwi 11,0; beq 10f; mr 3,31; li 4,2; bl _s80094B8C_11; b 12f; 10:; cmpwi 9,0; li 9,0; bne 11f; lwz 0,0x2c(31); cmpwi 0,0; beq 11f; li 9,1; 11:; cmpwi 9,0; beq 12f; mr 3,31; li 4,1; bl _s80094B8C_12; 12:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80094B8C_13; lis 3,-32706; addi 3,3,-31376; bl _s80094B8C_14; mr 4,3; li 5,0; lis 3,-32697; addi 3,3,23428; bl _s80094B8C_15; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80094B8C_0();
extern "C" void _s80094B8C_1();
extern "C" void _s80094B8C_2();
extern "C" void _s80094B8C_3();
extern "C" void _s80094B8C_4();
extern "C" void _s80094B8C_5();
extern "C" void _s80094B8C_6();
extern "C" void _s80094B8C_7();
extern "C" void _s80094B8C_8();
extern "C" void _s80094B8C_9();
extern "C" void _s80094B8C_10();
extern "C" void _s80094B8C_11();
extern "C" void _s80094B8C_12();
extern "C" void _s80094B8C_13();
extern "C" void _s80094B8C_14();
extern "C" void _s80094B8C_15();
extern "C" void f_80094B8C() {}
