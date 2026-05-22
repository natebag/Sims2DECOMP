// 0x80231240 Outside(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); li 0,0; mr 31,6; sth 0,0x0(5); sth 0,0x0(31); lwz 3,-21472(13); cmpwi 3,0; beq 0f; lhz 4,0x0(5); li 0,0; ori 0,0,65530; cmplw 4,0; bgt 0f; bl _s80231240_0; mr. 3,3; beq 0f; lhz 0,0x2(3); sth 0,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80231240_0();
extern "C" void f_80231240() {}
