// 0x80298FE8 AptPseudoCIH_t::AptPseudoCIH_t(AptControl (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; mr 28,7; stw 6,0x10(31); cmpwi 30,0; stw 30,0x0(31); beq 0f; lwz 0,0x0(30); cmpwi 0,3; bne 0f; lwz 3,-23020(13); li 4,28; bl _s80298FE8_0; mr 4,30; mr 5,29; mr 6,28; bl _s80298FE8_1; stw 3,0x4(31); b 1f; 0:; li 0,0; stw 0,0x4(31); 1:; li 0,0; mr 3,31; stw 0,0xc(31); stw 0,0x8(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80298FE8_0();
extern "C" void _s80298FE8_1();
extern "C" void f_80298FE8() {}
