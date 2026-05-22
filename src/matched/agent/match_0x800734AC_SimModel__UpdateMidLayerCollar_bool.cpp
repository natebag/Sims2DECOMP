// 0x800734AC SimModel::UpdateMidLayerCollar(bool) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x98(31); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; li 4,10; bl _s800734AC_0; b 1f; 0:; mr 3,31; li 4,10; li 5,0; li 6,0; bl _s800734AC_1; cmpwi 30,0; beq 1f; addi 4,31,104; addi 3,1,8; bl _s800734AC_2; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s800734AC_3; addi 3,1,8; li 4,2; bl _s800734AC_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800734AC_0();
extern "C" void _s800734AC_1();
extern "C" void _s800734AC_2();
extern "C" void _s800734AC_3();
extern "C" void _s800734AC_4();
extern "C" void f_800734AC() {}
