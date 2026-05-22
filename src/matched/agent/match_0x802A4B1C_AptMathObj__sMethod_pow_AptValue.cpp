// 0x802A4B1C AptMathObj::sMethod_pow(AptValue (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); cmpwi 4,1; bgt 0f; lwz 3,-22936(13); b 4f; 0:; lis 9,-32694; lwz 10,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); addi 11,10,-1; rlwinm 10,10,2,0,29; rlwinm 11,11,2,0,29; add 10,10,0; add 11,11,0; lwz 3,-4(10); lwz 30,-4(11); bl _s802A4B1C_0; fmr f31,f1; mr 3,30; bl _s802A4B1C_1; fmr f2,f1; fmr f1,f31; bl _s802A4B1C_2; lwz 3,-26912(13); fmr f31,f1; cmpwi 3,0; beq 3f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 2:; stfs f31,0xc(3); b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s802A4B1C_3; mr 30,3; li 4,6; bl _s802A4B1C_4; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; mr 3,30; stw 9,0x8(30); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802A4B1C_0();
extern "C" void _s802A4B1C_1();
extern "C" void _s802A4B1C_2();
extern "C" void _s802A4B1C_3();
extern "C" void _s802A4B1C_4();
extern "C" void f_802A4B1C() {}
