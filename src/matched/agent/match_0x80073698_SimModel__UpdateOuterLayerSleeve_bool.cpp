// 0x80073698 SimModel::UpdateOuterLayerSleeve(bool, (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,5; mr 29,6; mr 30,7; cmpwi 4,0; beq 1f; li 4,14; li 5,0; li 6,0; bl _s80073698_0; cmpwi 30,0; beq 0f; mr 3,31; li 4,1; li 5,0; li 6,0; li 7,0; bl _s80073698_1; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s80073698_2; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s80073698_3; 0:; cmpwi 29,0; beq 1f; addi 4,31,104; addi 3,1,8; bl _s80073698_4; lwz 9,0x13c(31); addi 3,1,8; li 4,1; lfs f1,0xfc(9); bl _s80073698_5; addi 3,1,8; li 4,2; bl _s80073698_6; 1:; cmpwi 28,0; beq 2f; lis 9,-32696; mr 3,31; lbz 4,0x5725(9); bl _s80073698_7; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80073698_0();
extern "C" void _s80073698_1();
extern "C" void _s80073698_2();
extern "C" void _s80073698_3();
extern "C" void _s80073698_4();
extern "C" void _s80073698_5();
extern "C" void _s80073698_6();
extern "C" void _s80073698_7();
extern "C" void f_80073698() {}
