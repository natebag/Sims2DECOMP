// 0x802A3FA8 AptMathObj::sMethod_round(AptValue (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); cmpwi 4,0; bgt 0f; lwz 3,-22936(13); b 6f; 0:; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802A3FA8_0; lis 9,-32703; lfs f0,-21360(9); fcmpu 0,f1,f0; cror 3,2,0; bso 1f; lis 9,-32703; lfs f0,-21356(9); fadds f0,f1,f0; b 2f; 1:; lis 9,-32703; lfs f0,-21356(9); fsubs f0,f1,f0; 2:; fctiwz f13,f0; stfd f13,0x8(1); lwz 31,0xc(1); lwz 3,-26908(13); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stw 31,0xc(3); b 6f; 5:; lwz 3,-23020(13); li 4,16; bl _s802A3FA8_1; mr 30,3; li 4,7; bl _s802A3FA8_2; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802A3FA8_0();
extern "C" void _s802A3FA8_1();
extern "C" void _s802A3FA8_2();
extern "C" void f_802A3FA8() {}
