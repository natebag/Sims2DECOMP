// 0x8031B4C8 ERMovie::ERMovie(EFile (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 29,5; mr 28,6; mr 27,7; bl _s8031B4C8_0; lis 9,-32697; li 0,0; addi 9,9,-19112; stw 30,0x14(31); stw 0,0x24(31); stw 9,0x0(31); stw 29,0x18(31); stw 28,0x1c(31); stw 27,0x20(31); lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0x24(31); mr 4,30; mr 5,29; mr 6,28; lwz 9,0x8(3); mr 7,27; lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; mr. 30,3; bne 0f; lwz 3,-26392(13); lwz 4,0x24(31); lwz 9,0x0(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; stw 30,0x24(31); 0:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8031B4C8_0();
extern "C" void f_8031B4C8() {}
