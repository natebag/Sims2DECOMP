// 0x80074220 SimModel::UpdateFacialFeature(bool, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,5; mr 30,6; cmpwi 4,0; beq 0f; li 4,18; li 5,0; li 6,0; bl _s80074220_0; cmpwi 30,0; beq 0f; addi 4,31,104; addi 3,1,8; bl _s80074220_1; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s80074220_2; addi 3,1,8; li 4,2; bl _s80074220_3; 0:; cmpwi 29,0; beq 1f; lis 9,-32696; mr 3,31; lbz 4,0x574d(9); bl _s80074220_4; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80074220_0();
extern "C" void _s80074220_1();
extern "C" void _s80074220_2();
extern "C" void _s80074220_3();
extern "C" void _s80074220_4();
extern "C" void f_80074220() {}
