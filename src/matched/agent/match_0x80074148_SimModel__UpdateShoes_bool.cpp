// 0x80074148 SimModel::UpdateShoes(bool, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,5; mr 30,6; cmpwi 4,0; beq 2f; li 4,16; li 5,0; li 6,0; bl _s80074148_0; lwz 9,0x13c(31); lwz 0,0xd0(9); cmpwi 0,0; beq 0f; mr 3,31; li 4,17; li 5,0; li 6,0; bl _s80074148_1; b 1f; 0:; mr 3,31; li 4,17; bl _s80074148_2; 1:; cmpwi 30,0; beq 2f; lwz 9,0x13c(31); lwz 0,0xd0(9); cmpwi 0,0; beq 2f; addi 4,31,104; addi 3,1,8; bl _s80074148_3; lwz 9,0x13c(31); addi 3,1,8; li 4,3; lfs f1,0x100(9); bl _s80074148_4; addi 3,1,8; li 4,2; bl _s80074148_5; 2:; cmpwi 29,0; beq 3f; lis 9,-32696; mr 3,31; lbz 4,0x5739(9); bl _s80074148_6; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80074148_0();
extern "C" void _s80074148_1();
extern "C" void _s80074148_2();
extern "C" void _s80074148_3();
extern "C" void _s80074148_4();
extern "C" void _s80074148_5();
extern "C" void _s80074148_6();
extern "C" void f_80074148() {}
