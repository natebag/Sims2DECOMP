// 0x800AC880 ResourceBehavior::~ResourceBehavior(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-6112; mr 30,4; stw 9,0x0(31); lwz 3,0x10(31); cmpwi 3,0; beq 0f; bl _s800AC880_0; li 0,0; stw 0,0x10(31); 0:; lwz 3,0x14(31); cmpwi 3,0; beq 1f; bl _s800AC880_1; li 0,0; stw 0,0x14(31); 1:; lwz 3,0x18(31); cmpwi 3,0; beq 2f; bl _s800AC880_2; li 0,0; stw 0,0x18(31); 2:; mr 3,31; mr 4,30; bl _s800AC880_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800AC880_0();
extern "C" void _s800AC880_1();
extern "C" void _s800AC880_2();
extern "C" void _s800AC880_3();
extern "C" void f_800AC880() {}
