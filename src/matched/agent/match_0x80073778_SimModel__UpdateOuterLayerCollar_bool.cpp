// 0x80073778 SimModel::UpdateOuterLayerCollar(bool, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 31,3; mr 29,5; li 4,13; li 5,0; li 6,0; bl _s80073778_0; cmpwi 30,0; beq 0f; addi 4,31,104; addi 3,1,8; bl _s80073778_1; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s80073778_2; addi 3,1,8; li 4,2; bl _s80073778_3; 0:; cmpwi 29,0; beq 1f; lwz 9,0x13c(31); lwz 3,0x138(31); lbz 4,0xb4(9); lwz 5,0xbc(9); extsb 4,4; bl _s80073778_4; cmpwi 3,0; beq 1f; mr 3,31; li 4,2; bl _s80073778_5; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80073778_0();
extern "C" void _s80073778_1();
extern "C" void _s80073778_2();
extern "C" void _s80073778_3();
extern "C" void _s80073778_4();
extern "C" void _s80073778_5();
extern "C" void f_80073778() {}
