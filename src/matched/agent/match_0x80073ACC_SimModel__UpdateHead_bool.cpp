// 0x80073ACC SimModel::UpdateHead(bool, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,5; mr 30,6; cmpwi 4,0; beq 0f; li 4,1; li 5,0; li 6,0; bl _s80073ACC_0; cmpwi 30,0; beq 0f; addi 3,1,8; addi 4,31,104; bl _s80073ACC_1; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s80073ACC_2; lwz 9,0x13c(31); li 4,0; addi 3,1,8; lfs f1,0xf8(9); bl _s80073ACC_3; mr 3,31; bl _s80073ACC_4; addi 3,1,8; li 4,2; bl _s80073ACC_5; 0:; cmpwi 29,0; beq 1f; lis 9,-32696; mr 3,31; lbz 4,0x5757(9); bl _s80073ACC_6; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80073ACC_0();
extern "C" void _s80073ACC_1();
extern "C" void _s80073ACC_2();
extern "C" void _s80073ACC_3();
extern "C" void _s80073ACC_4();
extern "C" void _s80073ACC_5();
extern "C" void _s80073ACC_6();
extern "C" void f_80073ACC() {}
