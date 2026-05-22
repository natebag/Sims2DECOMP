// 0x80073544 SimModel::UpdateOuterLayerTorso(bool, (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,5; mr 29,6; mr 30,7; cmpwi 4,0; beq 2f; li 4,12; li 5,0; li 6,0; bl _s80073544_0; cmpwi 30,0; beq 0f; li 5,0; li 6,0; li 7,0; mr 3,31; li 4,1; bl _s80073544_1; mr 3,31; li 4,0; bl _s80073544_2; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s80073544_3; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s80073544_4; 0:; addi 9,31,104; mr 30,9; lwz 9,0x30(9); cmpwi 9,0; beq 1f; lwz 0,0x120(9); cmpwi 0,0; beq 1f; mr 3,31; li 4,25; bl _s80073544_5; 1:; cmpwi 29,0; beq 2f; mr 4,30; addi 3,1,8; bl _s80073544_6; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s80073544_7; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s80073544_8; addi 3,1,8; li 4,2; bl _s80073544_9; 2:; cmpwi 28,0; beq 4f; lwz 9,0x13c(31); lwz 3,0x138(31); lbz 4,0xb4(9); lwz 5,0xb8(9); extsb 4,4; bl _s80073544_10; cmpwi 3,0; beq 3f; mr 3,31; li 4,2; bl _s80073544_11; 3:; lis 9,-32696; mr 3,31; lbz 4,0x5711(9); bl _s80073544_12; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80073544_0();
extern "C" void _s80073544_1();
extern "C" void _s80073544_2();
extern "C" void _s80073544_3();
extern "C" void _s80073544_4();
extern "C" void _s80073544_5();
extern "C" void _s80073544_6();
extern "C" void _s80073544_7();
extern "C" void _s80073544_8();
extern "C" void _s80073544_9();
extern "C" void _s80073544_10();
extern "C" void _s80073544_11();
extern "C" void _s80073544_12();
extern "C" void f_80073544() {}
