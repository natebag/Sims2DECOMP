// 0x80310778 EResourceLoaderImpl::Load(EResourceManager (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 11,0x0(31); mr 29,5; mr 26,6; mr 25,7; lha 3,0x28(11); mr 24,8; lwz 0,0x2c(11); mr 27,9; add 3,31,3; li 28,0; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; mr 3,31; mr 4,30; mr 5,29; mr 6,26; mr 7,25; mr 8,24; bl _s80310778_0; mr 28,3; b 1f; 0:; addi 3,31,888; bl _s80310778_1; li 3,40; bl _s80310778_2; bl _s80310778_3; mr 9,3; li 0,3; stw 0,0x0(9); mr 4,9; stw 26,0xc(9); mr 3,31; stw 25,0x10(9); stw 24,0x14(9); stw 29,0x8(9); stw 30,0x4(9); stw 27,0x20(9); bl _s80310778_4; cmpwi 27,0; beq 1f; lwz 9,0x0(31); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; mr 4,29; bl _s80310778_5; lwz 0,-26824(13); mr 28,3; cmpwi 0,0; beq 1f; mr 3,0; bl _s80310778_6; 1:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80310778_0();
extern "C" void _s80310778_1();
extern "C" void _s80310778_2();
extern "C" void _s80310778_3();
extern "C" void _s80310778_4();
extern "C" void _s80310778_5();
extern "C" void _s80310778_6();
extern "C" void f_80310778() {}
