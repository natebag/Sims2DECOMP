// 0x802EA9E0 EAnimController::BlendNodeArrays(EACTrack (824 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stfd f23,0x70(1); stfd f24,0x78(1); stfd f25,0x80(1); stfd f26,0x88(1); stfd f27,0x90(1); stfd f28,0x98(1); stfd f29,0xa0(1); stfd f30,0xa8(1); stfd f31,0xb0(1); stmw 20,0x40(1); stw 0,0xbc(1); mr 22,4; lwz 9,0x24(3); lwz 0,0x8(22); mr 30,5; lfs f25,0x50(22); mr 31,6; cmpwi 9,0; rlwinm 20,0,0,23,23; li 23,0; beq 0f; lwz 23,0x18(9); 0:; li 28,0; cmpw 28,23; bge 14f; lis 9,-32702; lis 11,-32702; lfs f23,-4552(9); lis 10,-32702; lfs f26,-4548(11); lis 9,-32702; lis 11,-32702; lfs f28,-4560(10); lfs f24,-4544(9); addi 24,1,8; lfs f27,-4556(11); addi 21,1,24; 1:; lwz 11,0x9c(22); fmr f31,f25; cmpwi 11,0; beq 2f; rlwinm 9,28,2,0,29; lfsx f0,9,11; fmuls f31,f31,f0; 2:; lis 9,-32702; addi 25,30,68; lfs f30,-4560(9); addi 26,31,68; addi 27,28,1; fcmpu 0,f31,f30; beq 13f; cmpwi 20,0; beq 3f; fmr f1,f31; mr 3,31; mr 4,30; bl _s802EA9E0_0; b 13f; 3:; lis 9,-32702; lfs f0,-4556(9); fcmpu 0,f31,f0; bne 5f; mr 3,31; mr 4,30; li 9,48; 4:; lwz 0,0x0(4); addic. 9,9,-24; stw 0,0x0(3); lwz 0,0x4(4); stw 0,0x4(3); lwz 0,0x8(4); stw 0,0x8(3); lwz 0,0xc(4); stw 0,0xc(3); lwz 0,0x10(4); stw 0,0x10(3); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(3); addi 3,3,24; bne 4b; lwz 0,0x0(4); stw 0,0x0(3); lwz 0,0x4(4); stw 0,0x4(3); lwz 0,0x8(4); stw 0,0x8(3); lwz 0,0xc(4); stw 0,0xc(3); lwz 0,0x10(4); stw 0,0x10(3); b 13f; 5:; stfs f30,0x8(1); addi 9,31,20; stfs f0,0x8(24); addi 3,31,4; stfs f30,0x4(24); mr 29,3; mr 4,24; lfs f0,0x14(31); stfs f0,0x18(1); lfs f13,0x4(9); stfs f13,0x1c(1); lfs f0,0x8(9); stfs f0,0x20(1); bl _s802EA9E0_1; fmr f29,f1; mr 3,31; fmr f1,f31; mr 4,30; bl _s802EA9E0_2; cmpwi 28,1; bgt 13f; lfs f10,0x18(1); stfs f10,0x30(1); lfs f13,0x4(21); stfs f13,0x34(1); lfs f0,0x14(30); stfs f0,0x38(1); fsubs f0,f10,f0; lfs f12,0x18(30); stfs f0,0x28(1); fsubs f13,f13,f12; stfs f12,0x3c(1); fmuls f11,f13,f13; stfs f13,0x2c(1); fmadds f0,f0,f0,f11; fcmpu 0,f0,f23; ble 6f; stfs f10,0x14(31); lfs f0,0x1c(1); stfs f0,0x18(31); 6:; lfs f0,0x20(1); lfs f13,0x1c(30); fmr f12,f0; fsubs f0,f0,f13; fcmpu 0,f0,f30; cror 3,2,1; bns 7f; fcmpu 0,f0,f26; bgt 8f; b 9f; 7:; fneg f0,f0; fcmpu 0,f0,f26; ble 9f; 8:; stfs f12,0x1c(31); 9:; addi 3,30,4; addi 4,1,8; bl _s802EA9E0_3; fsubs f0,f29,f1; fcmpu 0,f0,f28; cror 3,2,1; bso 10f; fneg f0,f0; 10:; addi 25,30,68; addi 26,31,68; addi 27,28,1; fcmpu 0,f0,f24; lfs f11,-22724(13); ble 12f; lis 9,-32702; lis 11,-32702; lfs f12,-4540(9); lfs f13,-4544(11); 11:; fsubs f0,f0,f12; fcmpu 0,f0,f13; bgt 11b; 12:; fcmpu 0,f0,f11; ble 13f; addi 4,1,8; mr 3,29; stfs f27,0x8(1); stfs f28,0x10(1); bl _s802EA9E0_4; fmr f31,f1; mr 3,29; stfs f28,0x8(1); addi 4,1,8; stfs f27,0xc(1); bl _s802EA9E0_5; fmr f2,f1; mr 3,29; fmr f1,f31; fmr f3,f29; bl _s802EA9E0_6; 13:; mr 28,27; mr 30,25; mr 31,26; cmpw 28,23; blt 1b; 14:; lwz 0,0xbc(1); mtspr 8,0; lmw 20,0x40(1); lfd f23,0x70(1); lfd f24,0x78(1); lfd f25,0x80(1); lfd f26,0x88(1); lfd f27,0x90(1); lfd f28,0x98(1); lfd f29,0xa0(1); lfd f30,0xa8(1); lfd f31,0xb0(1); addi 1,1,184"

extern "C" void _s802EA9E0_0();
extern "C" void _s802EA9E0_1();
extern "C" void _s802EA9E0_2();
extern "C" void _s802EA9E0_3();
extern "C" void _s802EA9E0_4();
extern "C" void _s802EA9E0_5();
extern "C" void _s802EA9E0_6();

struct EAnimController {
    void BlendNodeArrays();
};

void EAnimController::BlendNodeArrays() {
}
