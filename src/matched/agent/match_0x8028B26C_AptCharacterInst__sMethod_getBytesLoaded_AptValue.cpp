// 0x8028B26C AptCharacterInst::sMethod_getBytesLoaded(AptValue (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 29,0x2c(1); stw 0,0x44(1); lis 11,-32700; mr 30,3; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 29,1,8; addi 9,9,1; li 10,0; sth 9,-6476(11); lwz 0,0x0(30); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 10,0,5,31,31; 0:; cmpwi 10,0; beq 2f; mr 3,30; li 31,0; bl _s8028B26C_0; cmpwi 3,18; bne 1f; mr 3,30; bl _s8028B26C_1; subfic 0,3,0; adde 31,0,3; 1:; cmpwi 31,0; beq 2f; lwz 9,0x4c(30); mr 3,29; lwz 4,0x34(9); addi 4,4,4; bl _s8028B26C_2; 2:; lis 9,-32704; mr 3,30; lfs f31,0x4d40(9); li 31,0; bl _s8028B26C_3; cmpwi 3,18; bne 3f; mr 3,30; bl _s8028B26C_4; subfic 0,3,0; adde 31,0,3; 3:; cmpwi 31,0; beq 4f; lis 9,-32694; lwz 3,0x8(1); lwz 0,-16136(9); li 4,0; addi 3,3,8; mtspr 8,0; blrl; xoris 3,3,32768; stw 3,0x24(1); lis 0,17200; lis 11,-32704; stw 0,0x20(1); lfd f13,0x4d48(11); lfd f0,0x20(1); fsub f0,f0,f13; frsp f31,f0; 4:; lwz 3,-26912(13); cmpwi 3,0; beq 7f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 5f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 6f; 5:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 6:; stfs f31,0xc(3); mr 31,3; b 8f; 7:; lwz 3,-23020(13); li 4,16; bl _s8028B26C_5; mr 30,3; li 4,6; mr 31,30; bl _s8028B26C_6; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 8:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028B26C_7; 9:; mr 3,31; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x2c(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s8028B26C_0();
extern "C" void _s8028B26C_1();
extern "C" void _s8028B26C_2();
extern "C" void _s8028B26C_3();
extern "C" void _s8028B26C_4();
extern "C" void _s8028B26C_5();
extern "C" void _s8028B26C_6();
extern "C" void _s8028B26C_7();
extern "C" void f_8028B26C() {}
