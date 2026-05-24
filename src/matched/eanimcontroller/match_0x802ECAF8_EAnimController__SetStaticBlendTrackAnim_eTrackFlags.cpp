// 0x802ECAF8 EAnimController::SetStaticBlendTrackAnim(eTrackFlags, (1044 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stfd f28,0x30(1); stfd f29,0x38(1); stfd f30,0x40(1); stfd f31,0x48(1); stmw 24,0x10(1); stw 0,0x54(1); stw 12,0xc(1); mr 31,3; mr 25,5; mr 26,4; mr 28,6; lis 3,-32693; fmr f30,f1; fmr f28,f2; mr 24,7; addi 3,3,11064; mr 4,25; li 5,0; li 6,0; bl _s802ECAF8_0; li 30,0; mr. 27,3; beq 24f; lwz 11,0x38(31); lis 9,-32702; lfs f13,-4516(9); li 29,-1; addi 11,11,-1; li 7,0; cmpw 30,11; lwz 0,0x44(31); bgt 9f; mr 3,0; addi 4,3,80; 0:; lwz 0,0x8(31); cmpw 7,0; beq 7f; lwz 0,0x6c(31); li 10,0; mulli 6,7,176; mr 5,0; cmplw 10,0; bge 4f; lwz 9,0x70(31); lbz 0,0x0(9); mr 8,9; extsb 0,0; cmpw 0,7; bne 1f; lfs f0,0x0(4); b 2f; 1:; addi 10,10,1; cmplw 10,5; bge 4f; lbzx 0,8,10; extsb 0,0; cmpw 0,7; bne 1b; add 9,6,3; lfs f0,0x50(9); 2:; fcmpu 0,f0,f13; bge 3f; fmr f13,f0; mr 29,7; 3:; cmplw 10,5; blt 7f; 4:; add 9,6,3; lwz 0,0xa8(9); cmpwi 0,0; beq 5f; lwz 0,0x7c(9); cmpwi 0,0; bne 6f; 5:; stw 30,0xa8(9); lwz 9,0x44(31); add 9,6,9; stw 30,0x30(9); b 8f; 6:; lfs f0,0x50(9); fcmpu 0,f0,f13; bge 7f; fmr f13,f0; mr 29,7; 7:; addi 7,7,1; addi 4,4,176; cmpw 7,11; ble 0b; 8:; lwz 9,0x38(31); addi 9,9,-1; cmpw 7,9; ble 10f; 9:; mulli 30,29,176; lwz 4,0x44(31); mr 3,31; add 4,4,30; bl _s802ECAF8_1; lwz 0,0x44(31); add 30,0,30; b 11f; 10:; mulli 9,7,176; lwz 0,0x44(31); add 30,0,9; 11:; cmpwi 30,0; beq 24f; mr 3,31; mr 4,30; bl _s802ECAF8_2; lwz 3,0x7c(30); cmpwi 3,0; beq 12f; bl _s802ECAF8_3; li 0,0; stw 0,0x7c(30); 12:; oris 9,26,8; li 0,0; stw 0,0xa8(30); addi 8,27,100; stw 9,0x30(30); mr 7,30; stw 27,0x7c(30); li 29,24; fmr f29,f28; cmpwi 4,28,1; 13:; lwz 0,0x0(8); addic. 29,29,-24; stw 0,0x0(7); lwz 0,0x4(8); stw 0,0x4(7); lwz 0,0x8(8); stw 0,0x8(7); lwz 0,0xc(8); stw 0,0xc(7); lwz 0,0x10(8); stw 0,0x10(7); lwz 0,0x14(8); addi 8,8,24; stw 0,0x14(7); addi 7,7,24; bne 13b; lwz 0,0x0(8); lis 9,-32702; lfs f31,-4512(9); lis 11,-32702; stw 0,0x0(7); lis 10,-32702; lwz 0,0x4(8); lwz 9,-26812(13); stw 0,0x4(7); lwz 0,0x8(8); addi 9,9,-1; lfs f13,-4508(11); stw 0,0x8(7); lfs f0,-4504(10); lwz 0,0x74(30); stw 9,0x38(30); stfs f13,0x48(30); cmpwi 0,-1; stfs f0,0x4c(30); stw 29,0x24(30); stw 29,0x28(30); stfs f31,0x3c(30); stfs f31,0x40(30); stfs f13,0x44(30); beq 14f; mr 3,31; mr 4,30; li 5,0; fmr f1,f31; bl _s802ECAF8_4; 14:; stw 25,0xac(30); mr 3,31; stw 29,0x9c(30); mr 4,30; stfs f31,0x78(30); li 5,1; stw 29,0xa4(30); stb 28,0xa0(30); stfs f31,0x5c(30); stfs f31,0x50(30); bl _s802ECAF8_5; mr 5,24; mr 3,31; mr 4,30; fmr f1,f31; bl _s802ECAF8_6; lis 9,-32702; fmr f2,f28; lfd f0,-4496(9); fcmpu 0,f29,f0; bne 15f; lfs f2,-26732(13); 15:; beq cr4,17f; bgt cr4,16f; cmpwi 28,-1; beq 19f; cmpwi 28,0; beq 18f; b 19f; 16:; cmpwi 28,3; beq 21f; blt 22f; cmpwi 28,4; beq 24f; b 19f; 17:; fmr f3,f31; mr 3,31; fmr f1,f30; mr 4,30; fmr f4,f3; bl _s802ECAF8_7; b 24f; 18:; mr 3,31; fmr f1,f30; mr 4,30; li 5,1; bl _s802ECAF8_8; b 24f; 19:; lwz 9,0x7c(30); li 11,1; lwz 0,0x8(9); cmpwi 0,0; bne 20f; li 11,0; 20:; cmpwi 11,0; beq 23f; lwz 0,0x8(30); andi. 9,0,1024; beq 22f; 21:; mr 3,31; fmr f1,f30; mr 4,30; bl _s802ECAF8_9; b 24f; 22:; lis 9,-32702; mr 3,31; lfs f3,-4488(9); fmr f1,f30; mr 4,30; bl _s802ECAF8_10; b 24f; 23:; lis 9,-32702; mr 3,31; lfs f1,-4512(9); mr 4,30; li 5,1; bl _s802ECAF8_11; 24:; mr 3,30; lwz 0,0x54(1); lwz 12,0xc(1); mtspr 8,0; lmw 24,0x10(1); lfd f28,0x30(1); lfd f29,0x38(1); lfd f30,0x40(1); lfd f31,0x48(1); mtcrf 8,12; addi 1,1,80"

extern "C" void _s802ECAF8_0();
extern "C" void _s802ECAF8_1();
extern "C" void _s802ECAF8_2();
extern "C" void _s802ECAF8_3();
extern "C" void _s802ECAF8_4();
extern "C" void _s802ECAF8_5();
extern "C" void _s802ECAF8_6();
extern "C" void _s802ECAF8_7();
extern "C" void _s802ECAF8_8();
extern "C" void _s802ECAF8_9();
extern "C" void _s802ECAF8_10();
extern "C" void _s802ECAF8_11();

struct EAnimController {
    void SetStaticBlendTrackAnim();
};

void EAnimController::SetStaticBlendTrackAnim() {
}
