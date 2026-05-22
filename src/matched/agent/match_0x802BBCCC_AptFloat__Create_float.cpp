// 0x802BBCCC AptFloat::Create(float) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); lwz 3,-26912(13); fmr f31,f1; cmpwi 3,0; beq 2f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 1:; stfs f31,0xc(3); b 3f; 2:; lwz 3,-23020(13); li 4,16; bl _s802BBCCC_0; mr 30,3; li 4,6; bl _s802BBCCC_1; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; mr 3,30; stw 9,0x8(30); 3:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802BBCCC_0();
extern "C" void _s802BBCCC_1();
extern "C" void f_802BBCCC() {}
