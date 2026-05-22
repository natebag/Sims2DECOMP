// 0x80310A74 EResourceLoaderImpl::ReadData(EResourceManager (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,3; mr 28,4; lwz 11,0x0(31); mr 23,5; mr 25,6; mr 24,7; lha 3,0x28(11); mr 27,8; lwz 0,0x2c(11); mr 26,9; add 3,31,3; li 29,0; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 30,0x0(31); mr 3,28; lha 29,0x70(30); addi 30,30,112; add 29,31,29; bl _s80310A74_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 5,23; mr 6,25; mr 7,24; li 8,1; li 9,0; mtspr 8,0; blrl; b 2f; 0:; li 3,40; bl _s80310A74_1; bl _s80310A74_2; mr 30,3; li 0,5; stw 28,0x4(30); mr 3,31; stw 25,0x10(30); mr 4,30; stw 24,0x14(30); stw 23,0x1c(30); stw 26,0x18(30); stw 29,0x8(30); stw 29,0xc(30); stw 27,0x20(30); stw 0,0x0(30); bl _s80310A74_3; cmpwi 27,0; beq 1f; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,30; lwz 29,0x14(30); bl _s80310A74_4; 1:; mr 3,29; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80310A74_0();
extern "C" void _s80310A74_1();
extern "C" void _s80310A74_2();
extern "C" void _s80310A74_3();
extern "C" void _s80310A74_4();
extern "C" void f_80310A74() {}
