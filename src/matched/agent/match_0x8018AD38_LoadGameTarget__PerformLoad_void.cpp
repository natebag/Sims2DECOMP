// 0x8018AD38 LoadGameTarget::PerformLoad(void) (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-824(1); mfspr 0,8; stmw 29,0x32c(1); stw 0,0x33c(1); mr 31,3; li 30,1; stw 30,0x144(31); addi 3,1,8; li 29,0; bl _s8018AD38_0; lwz 0,0x138(31); andi. 9,0,4; bne 1f; bl _s8018AD38_1; lwz 3,0x128(31); lis 4,171; ori 4,4,52719; bl _s8018AD38_2; mr 30,3; cmpwi 30,1; beq 0f; lwz 3,-32056(13); bl _s8018AD38_3; b 1f; 0:; lis 3,-32697; addi 3,3,23428; bl _s8018AD38_4; lwz 29,-32056(13); 1:; cmpwi 30,1; beq 2f; li 0,0; stw 0,0x144(31); b 5f; 2:; lwz 0,0x138(31); andi. 9,0,2; beq 5f; cmpwi 29,0; bne 5f; addi 3,1,8; li 4,0; bl _s8018AD38_5; lis 4,21865; addi 3,1,8; ori 4,4,30840; bl _s8018AD38_6; cmpwi 3,0; bne 3f; lis 4,21865; lis 5,-32743; lis 6,-32743; lis 7,-32743; addi 5,5,-13124; addi 6,6,-21776; addi 7,7,-13120; addi 3,1,8; ori 4,4,30840; bl _s8018AD38_7; 3:; lwz 4,0x128(31); addi 3,1,8; bl _s8018AD38_8; cmpwi 3,1; bne 4f; addi 30,1,560; mr 3,30; bl _s8018AD38_9; lwz 4,0x128(31); mr 3,30; bl _s8018AD38_10; cmpwi 3,1; bne 4f; lwz 4,-31932(13); addi 3,1,8; lbz 5,0x12b(31); bl _s8018AD38_11; cmpwi 3,1; beq 5f; 4:; stw 29,0x144(31); 5:; lwz 30,0x144(31); addi 3,1,8; li 4,2; bl _s8018AD38_12; mr 3,30; lwz 0,0x33c(1); mtspr 8,0; lmw 29,0x32c(1); addi 1,1,824"
extern "C" void _s8018AD38_0();
extern "C" void _s8018AD38_1();
extern "C" void _s8018AD38_2();
extern "C" void _s8018AD38_3();
extern "C" void _s8018AD38_4();
extern "C" void _s8018AD38_5();
extern "C" void _s8018AD38_6();
extern "C" void _s8018AD38_7();
extern "C" void _s8018AD38_8();
extern "C" void _s8018AD38_9();
extern "C" void _s8018AD38_10();
extern "C" void _s8018AD38_11();
extern "C" void _s8018AD38_12();
extern "C" void f_8018AD38() {}
