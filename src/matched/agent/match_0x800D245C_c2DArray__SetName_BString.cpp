// 0x800D245C _c2DArray::SetName(BString (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 27,0x20c(1); stw 0,0x224(1); mr 31,3; mr 28,4; addi 30,31,16; bl _s800D245C_0; mr 29,30; mr 3,30; mr 4,28; bl _s800D245C_1; li 30,0; lis 27,-32706; 0:; mr 3,29; bl _s800D245C_2; cmpwi 3,0; beq 1f; mr 3,29; bl _s800D245C_3; cmpwi 3,0; li 0,0; beq 2f; 1:; li 0,1; 2:; cmpwi 0,0; beq 3f; mr 3,28; bl _s800D245C_4; mr 5,3; mr 6,30; addi 4,27,-21884; addi 3,1,8; crxor 6,6,6; bl _s800D245C_5; addi 30,30,1; addi 3,31,16; addi 4,1,8; bl _s800D245C_6; b 0b; 3:; mr 3,31; bl _s800D245C_7; lwz 0,0x224(1); mtspr 8,0; lmw 27,0x20c(1); addi 1,1,544"
extern "C" void _s800D245C_0();
extern "C" void _s800D245C_1();
extern "C" void _s800D245C_2();
extern "C" void _s800D245C_3();
extern "C" void _s800D245C_4();
extern "C" void _s800D245C_5();
extern "C" void _s800D245C_6();
extern "C" void _s800D245C_7();
extern "C" void f_800D245C() {}
