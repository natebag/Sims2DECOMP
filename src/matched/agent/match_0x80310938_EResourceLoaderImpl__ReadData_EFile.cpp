// 0x80310938 EResourceLoaderImpl::ReadData(EFile (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; mr 30,4; lwz 11,0x0(29); mr 23,5; mr 26,6; mr 24,7; lha 3,0x28(11); mr 25,8; lwz 0,0x2c(11); mr 28,9; add 3,29,3; li 27,0; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x28(30); mr 4,26; li 5,0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); mr 4,23; mr 5,24; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; mr 27,3; cmpwi 28,0; beq 1f; li 9,0; li 0,1; stw 0,0x0(28); stw 9,0x4(28); stw 27,0x8(28); b 1f; 0:; li 3,40; bl _s80310938_0; bl _s80310938_1; mr 31,3; li 0,5; stw 30,0xc(31); mr 3,29; stw 26,0x10(31); mr 4,31; stw 24,0x14(31); stw 23,0x1c(31); stw 28,0x18(31); stw 27,0x8(31); stw 27,0x4(31); stw 25,0x20(31); stw 0,0x0(31); bl _s80310938_2; cmpwi 25,0; beq 1f; lwz 9,0x0(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,29,3; mtspr 8,0; blrl; mr 3,31; lwz 27,0x14(31); bl _s80310938_3; 1:; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80310938_0();
extern "C" void _s80310938_1();
extern "C" void _s80310938_2();
extern "C" void _s80310938_3();
extern "C" void f_80310938() {}
