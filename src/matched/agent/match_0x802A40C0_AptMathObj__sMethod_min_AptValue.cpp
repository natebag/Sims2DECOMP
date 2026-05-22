// 0x802A40C0 AptMathObj::sMethod_min(AptValue (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); cmpwi 4,1; bgt 0f; lwz 3,-22936(13); b 6f; 0:; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 10,11,2,0,29; addi 11,11,-1; add 10,10,0; rlwinm 11,11,2,0,29; lwz 31,-4(10); add 11,11,0; lwz 30,-4(11); mr 3,31; bl _s802A40C0_0; fmr f31,f1; mr 3,30; bl _s802A40C0_1; fcmpu 0,f31,f1; cror 3,2,1; bso 1f; mr 3,31; b 2f; 1:; mr 3,30; 2:; bl _s802A40C0_2; fmr f31,f1; lwz 3,-26912(13); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stfs f31,0xc(3); b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s802A40C0_3; mr 30,3; li 4,6; bl _s802A40C0_4; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; mr 3,30; stw 9,0x8(30); 6:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802A40C0_0();
extern "C" void _s802A40C0_1();
extern "C" void _s802A40C0_2();
extern "C" void _s802A40C0_3();
extern "C" void _s802A40C0_4();
extern "C" void f_802A40C0() {}
