// 0x8015CF14 SmartDataFactory::CreateObject(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 27,4; lwz 30,0x0(29); mr 4,5; mr 28,6; li 5,0; lha 0,0x20(30); addi 3,1,8; addi 30,30,32; add 29,29,0; bl _s8015CF14_0; lwz 0,0x4(30); mr 3,29; mr 4,27; mr 6,28; addi 5,1,8; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8015CF14_0();
extern "C" void f_8015CF14() {}
