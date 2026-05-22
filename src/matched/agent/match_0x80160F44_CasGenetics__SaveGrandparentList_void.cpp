// 0x80160F44 CasGenetics::SaveGrandparentList(void) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); lis 4,17223; li 5,1; ori 4,4,18256; bl _s80160F44_0; mr. 31,3; bne 0f; li 3,0; b 3f; 0:; addi 30,1,8; addi 28,1,16; addi 29,1,24; mr 3,30; bl _s80160F44_1; lis 27,-32694; lis 4,-32706; mr 3,30; addi 4,4,-4192; li 26,0; bl _s80160F44_2; addi 3,1,16; bl _s80160F44_3; lwz 5,0x8(1); lis 4,-32706; addi 4,4,-4188; mr 3,28; crxor 6,6,6; bl _s80160F44_4; mr 3,28; bl _s80160F44_5; li 0,0; lwz 5,0x10(1); lis 6,-32706; stw 0,0x18(1); addi 6,6,-4168; addi 3,27,-10620; mr 4,29; li 7,2; lis 8,-32768; li 9,0; bl _s80160F44_6; cmpwi 3,0; beq 1f; lwz 11,0x18(1); lwz 4,0x4(31); lwz 9,0x28(11); lwz 5,0x0(31); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x0(31); mr 4,29; xor 26,3,0; subfic 9,26,0; adde 26,9,26; addi 3,27,-10620; bl _s80160F44_7; 1:; lwz 0,0x8(31); cmpwi 0,0; beq 2f; bl _s80160F44_8; lwz 4,0x4(31); bl _s80160F44_9; 2:; bl _s80160F44_10; mr 4,31; bl _s80160F44_11; lwz 4,0x10(1); mr 3,28; bl _s80160F44_12; lwz 4,0x8(1); mr 3,30; bl _s80160F44_13; mr 3,26; 3:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s80160F44_0();
extern "C" void _s80160F44_1();
extern "C" void _s80160F44_2();
extern "C" void _s80160F44_3();
extern "C" void _s80160F44_4();
extern "C" void _s80160F44_5();
extern "C" void _s80160F44_6();
extern "C" void _s80160F44_7();
extern "C" void _s80160F44_8();
extern "C" void _s80160F44_9();
extern "C" void _s80160F44_10();
extern "C" void _s80160F44_11();
extern "C" void _s80160F44_12();
extern "C" void _s80160F44_13();
extern "C" void f_80160F44() {}
