// 0x80073D60 SimModel::UpdateVestScarf(bool, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,5; mr 29,6; cmpwi 4,0; beq 1f; li 4,25; li 5,0; li 6,0; bl _s80073D60_0; addi 9,31,104; mr 30,9; lwz 9,0x64(9); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; mr 3,31; li 4,12; bl _s80073D60_1; mr 3,31; li 4,14; bl _s80073D60_2; mr 3,31; li 4,13; bl _s80073D60_3; 0:; cmpwi 29,0; beq 1f; mr 4,30; addi 3,1,8; bl _s80073D60_4; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s80073D60_5; addi 3,1,8; li 4,2; bl _s80073D60_6; 1:; cmpwi 28,0; beq 2f; lis 9,-32696; mr 3,31; lbz 4,0x5793(9); bl _s80073D60_7; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80073D60_0();
extern "C" void _s80073D60_1();
extern "C" void _s80073D60_2();
extern "C" void _s80073D60_3();
extern "C" void _s80073D60_4();
extern "C" void _s80073D60_5();
extern "C" void _s80073D60_6();
extern "C" void _s80073D60_7();
extern "C" void f_80073D60() {}
