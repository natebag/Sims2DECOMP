// 0x80032F34 ESim::ServiceNpcOrderTableCallback(ELevelDrawData (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); lwz 31,0x24(4); mr 30,3; lwz 29,0x98(30); lwz 0,0x528(31); cmpwi 0,0; beq 0f; lwz 9,0x0(31); addi 4,1,8; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; lwz 5,0x120(31); mr 4,29; addi 6,1,8; addi 3,31,820; bl _s80032F34_0; lwz 11,0x3d0(31); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,29; li 5,0; li 6,0; lha 0,0xd0(9); lwz 9,0xd4(9); add 3,3,0; mtspr 8,9; blrl; 0:; mr 3,31; mr 4,29; bl _s80032F34_1; li 0,0; stw 0,0xa8(30); stw 0,0xac(30); stw 0,0xb4(30); lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s80032F34_0();
extern "C" void _s80032F34_1();
extern "C" void f_80032F34() {}
