// 0x800731F8 SimModel::UpdateInnerLayerSleeve(bool, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,5; mr 28,6; cmpwi 4,0; li 29,0; beq 2f; addi 9,31,104; lwz 0,0x2c(9); mr 30,9; cmpwi 0,0; bne 0f; lwz 0,0x38(30); cmpwi 0,0; bne 0f; li 4,8; li 5,0; li 6,0; bl _s800731F8_0; li 29,1; b 1f; 0:; mr 3,31; li 4,8; bl _s800731F8_1; 1:; cmpwi 29,0; beq 2f; cmpwi 28,0; beq 2f; mr 4,30; addi 3,1,8; bl _s800731F8_2; lwz 9,0x13c(31); addi 3,1,8; li 4,1; lfs f1,0xfc(9); bl _s800731F8_3; addi 3,1,8; li 4,2; bl _s800731F8_4; 2:; cmpwi 27,0; beq 3f; lis 9,-32696; mr 3,31; lbz 4,0x56e9(9); bl _s800731F8_5; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800731F8_0();
extern "C" void _s800731F8_1();
extern "C" void _s800731F8_2();
extern "C" void _s800731F8_3();
extern "C" void _s800731F8_4();
extern "C" void _s800731F8_5();
extern "C" void f_800731F8() {}
