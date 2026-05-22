// 0x80312CB8 EResPrefetch::AddRef(char (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 9,-22652(13); mr 31,3; mr 28,5; lwz 11,0x0(9); lha 3,0xa0(11); lwz 0,0xa4(11); add 3,9,3; mtspr 8,0; blrl; mr 29,3; mr 4,28; bl _s80312CB8_0; cmpwi 3,0; bne 0f; lis 9,-32692; addi 27,9,-17464; lwz 0,0x8(27); cmpw 31,0; bne 0f; lwz 0,0x3dc(31); cmpw 0,29; bne 0f; lwz 0,0x3e0(31); cmpw 0,28; beq 1f; 0:; mr 3,31; bl _s80312CB8_1; mr 3,29; mr 4,28; li 5,0; li 6,0; bl _s80312CB8_2; b 2f; 1:; mr 3,31; addi 30,31,840; bl _s80312CB8_3; lwz 7,0x3fc(31); mr 3,30; lwz 8,0x3ec(31); mr 4,29; lwz 6,0x40c(31); mr 5,28; bl _s80312CB8_4; mr 5,30; mr 4,28; li 6,0; mr 3,29; bl _s80312CB8_5; mr 30,3; mr 4,31; mr 3,27; bl _s80312CB8_6; mr 3,30; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80312CB8_0();
extern "C" void _s80312CB8_1();
extern "C" void _s80312CB8_2();
extern "C" void _s80312CB8_3();
extern "C" void _s80312CB8_4();
extern "C" void _s80312CB8_5();
extern "C" void _s80312CB8_6();
extern "C" void f_80312CB8() {}
