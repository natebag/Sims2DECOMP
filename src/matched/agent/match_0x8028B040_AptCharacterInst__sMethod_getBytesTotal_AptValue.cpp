// 0x8028B040 AptCharacterInst::sMethod_getBytesTotal(AptValue (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 29,0x2c(1); stw 0,0x44(1); lis 11,-32700; mr 30,3; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 29,1,8; addi 9,9,1; sth 9,-6476(11); lwz 0,0x4c(30); cmpwi 0,0; bne 0f; lwz 3,-26912(13); lis 9,-32704; lfs f31,0x4d34(9); cmpwi 3,0; beq 9f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 6f; b 7f; 0:; lwz 0,0x0(30); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 1f; rlwinm 11,0,5,31,31; 1:; cmpwi 11,0; beq 3f; mr 3,30; li 31,0; bl _s8028B040_0; cmpwi 3,18; bne 2f; mr 3,30; bl _s8028B040_1; subfic 0,3,0; adde 31,0,3; 2:; cmpwi 31,0; beq 3f; lwz 9,0x4c(30); mr 3,29; lwz 4,0x34(9); addi 4,4,4; bl _s8028B040_2; 3:; lis 9,-32704; mr 3,30; lfs f31,0x4d34(9); li 31,0; bl _s8028B040_3; cmpwi 3,18; bne 4f; mr 3,30; bl _s8028B040_4; subfic 0,3,0; adde 31,0,3; 4:; cmpwi 31,0; beq 5f; lis 9,-32694; lwz 3,0x8(1); lwz 0,-16140(9); li 4,0; addi 3,3,8; mtspr 8,0; blrl; xoris 3,3,32768; stw 3,0x24(1); lis 0,17200; lis 11,-32704; stw 0,0x20(1); lfd f13,0x4d38(11); lfd f0,0x20(1); fsub f0,f0,f13; frsp f31,f0; 5:; lwz 3,-26912(13); cmpwi 3,0; beq 9f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 7f; 6:; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 8f; 7:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 8:; stfs f31,0xc(3); mr 31,3; b 10f; 9:; lwz 3,-23020(13); li 4,16; bl _s8028B040_5; mr 30,3; li 4,6; mr 31,30; bl _s8028B040_6; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 10:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028B040_7; 11:; mr 3,31; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x2c(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s8028B040_0();
extern "C" void _s8028B040_1();
extern "C" void _s8028B040_2();
extern "C" void _s8028B040_3();
extern "C" void _s8028B040_4();
extern "C" void _s8028B040_5();
extern "C" void _s8028B040_6();
extern "C" void _s8028B040_7();
extern "C" void f_8028B040() {}
