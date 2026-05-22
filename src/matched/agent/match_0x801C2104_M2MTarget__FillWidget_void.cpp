// 0x801C2104 M2MTarget::FillWidget(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,-1; stw 0,0x18c(31); bl _s801C2104_0; li 30,0; lwz 0,0x188(31); cmpw 30,0; bge 2f; 0:; mr 3,31; mr 4,30; bl _s801C2104_1; cmpwi 3,0; beq 1f; lwz 0,0x18c(31); cmpwi 0,-1; bne 1f; stw 30,0x18c(31); 1:; lwz 0,0x188(31); addi 30,30,1; cmpw 30,0; blt 0b; 2:; lwz 0,0x18c(31); cmpwi 0,-1; bne 3f; li 0,0; stw 0,0x18c(31); 3:; mr 3,31; addi 30,31,288; bl _s801C2104_2; mr 3,31; bl _s801C2104_3; mr 3,30; bl _s801C2104_4; lis 4,-32705; li 5,0; addi 4,4,9084; mr 3,30; bl _s801C2104_5; lis 4,-32705; mr 3,30; addi 4,4,3316; bl _s801C2104_6; mr 3,30; bl _s801C2104_7; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C2104_0();
extern "C" void _s801C2104_1();
extern "C" void _s801C2104_2();
extern "C" void _s801C2104_3();
extern "C" void _s801C2104_4();
extern "C" void _s801C2104_5();
extern "C" void _s801C2104_6();
extern "C" void _s801C2104_7();
extern "C" void f_801C2104() {}
