// 0x803424E0 ENgcRenderer::WeightedBlend(_GXPrimitive, (920 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; mfcr 12; stfd f27,0xd0(1); stfd f28,0xd8(1); stfd f29,0xe0(1); stfd f30,0xe8(1); stfd f31,0xf0(1); stmw 14,0x88(1); stw 0,0xfc(1); stw 12,0x84(1); lwz 0,-26232(13); mr 30,6; stw 3,0x68(1); mr 20,7; mr 3,4; stw 5,0x6c(1); mr 23,8; mr 24,9; mr 17,10; cmpwi 0,0; beq 9f; lwz 9,-26252(13); li 0,0; stw 0,-26196(13); cmpwi 9,0; beq 9f; mr 0,5; li 4,7; rlwinm 5,0,0,16,31; bl _s803424E0_0; lwz 0,0x6c(1); li 6,0; cmpw 6,0; bge 9f; lis 9,-32702; lis 11,-32702; lfs f29,0x1d90(9); lis 22,-13311; lfd f27,0x1d98(11); 0:; lfs f0,0x0(30); cmpwi 4,20,0; stfs f0,0x8(1); lfs f13,0x4(30); stfs f13,0xc(1); lfs f0,0x8(30); stfs f29,0x30(1); stfs f0,0x10(1); stfs f29,0x2c(1); stfs f29,0x28(1); beq cr4,1f; lbz 0,0x0(20); lbz 9,0x1(20); mr 7,10; extsb 0,0; lbz 11,0x2(20); xoris 0,0,32768; extsb 9,9; stw 0,0x7c(1); xoris 9,9,32768; lis 0,17200; extsb 11,11; stw 0,0x78(1); mr 8,10; xoris 11,11,32768; stfs f29,0x40(1); lfd f0,0x78(1); stw 9,0x7c(1); fsub f0,f0,f27; stfs f29,0x3c(1); stw 0,0x78(1); frsp f0,f0; stfs f0,0x18(1); lfd f13,0x78(1); stw 11,0x7c(1); fsub f13,f13,f27; stfs f29,0x38(1); stw 0,0x78(1); frsp f13,f13; stfs f13,0x1c(1); lfd f0,0x78(1); fsub f0,f0,f27; frsp f0,f0; stfs f0,0x20(1); 1:; lis 9,-32702; lis 10,-32702; lfd f30,0x1da0(9); lis 11,-32700; lwz 9,0x68(1); addi 18,30,16; lfs f28,0x1da8(10); addi 21,11,11688; addi 14,6,1; li 25,0; addi 19,17,4; lis 16,-13311; cmpwi 3,24,0; lis 15,17200; cmpwi 2,23,0; addi 29,1,72; addi 27,1,40; addi 30,1,88; addi 28,1,56; addi 31,9,17780; 2:; lbzx 0,17,25; li 26,0; cmpwi 0,0; beq 3f; mr 5,29; stw 0,0x7c(1); addi 4,1,8; mr 3,31; li 26,1; stw 15,0x78(1); lfd f0,0x78(1); fsub f0,f0,f30; frsp f0,f0; fdivs f31,f0,f28; bl _s803424E0_1; mr 3,29; mr 4,29; fmr f1,f31; bl _s803424E0_2; mr 3,27; mr 4,29; mr 5,27; bl _s803424E0_3; beq cr4,3f; mr 5,30; addi 4,1,24; mr 3,31; bl _s803424E0_4; mr 3,30; mr 4,30; fmr f1,f31; bl _s803424E0_5; mr 3,28; mr 4,30; mr 5,28; bl _s803424E0_6; 3:; rlwinm 0,26,2,0,29; addi 25,25,1; lwzx 9,21,0; addi 31,31,48; cmpwi 25,3; addi 9,9,1; stwx 9,21,0; ble 2b; lfs f0,0x28(1); mr 17,19; lfs f12,0x2c(1); mr 30,18; stfs f0,-32768(22); lfs f13,0x30(1); stfs f12,-32768(22); stfs f13,-32768(22); beq cr4,5f; addi 31,1,56; mr 3,31; bl _s803424E0_7; fcmpu 0,f1,f29; beq 4f; mr 3,31; mr 4,31; bl _s803424E0_8; lis 9,-32702; mr 3,31; lfs f1,0x1dac(9); mr 4,3; bl _s803424E0_9; 4:; lfs f0,0x38(1); lfs f13,0x3c(1); mr 10,8; fctiwz f12,f0; addi 20,20,4; stfd f12,0x78(1); fctiwz f11,f13; lfs f0,0x40(1); lwz 8,0x7c(1); stfd f11,0x78(1); fctiwz f13,f0; extsb 9,8; lwz 10,0x7c(1); stfd f13,0x78(1); stb 9,-32768(16); extsb 0,10; lwz 11,0x7c(1); stb 0,-32768(16); extsb 9,11; stb 8,0x48(1); stb 9,-32768(16); stb 10,0x49(1); stb 11,0x4a(1); 5:; beq cr3,6f; lbz 0,0x0(24); lbz 9,0x1(24); lbz 11,0x2(24); lbz 10,0x3(24); stb 0,-32768(22); addi 24,24,4; stb 9,-32768(22); stb 11,-32768(22); stb 10,-32768(22); 6:; beq cr2,8f; lfs f13,0x0(23); lfs f0,0x4(23); lwz 0,0x100(1); stfs f13,-32768(22); cmpwi 0,0; stfs f0,-32768(22); beq 7f; addi 23,23,16; b 8f; 7:; addi 23,23,8; 8:; lwz 9,0x6c(1); mr 6,14; cmpw 6,9; blt 0b; 9:; lwz 0,0xfc(1); lwz 12,0x84(1); mtspr 8,0; lmw 14,0x88(1); lfd f27,0xd0(1); lfd f28,0xd8(1); lfd f29,0xe0(1); lfd f30,0xe8(1); lfd f31,0xf0(1); mtcrf 56,12; addi 1,1,248"

extern "C" void _s803424E0_0();
extern "C" void _s803424E0_1();
extern "C" void _s803424E0_2();
extern "C" void _s803424E0_3();
extern "C" void _s803424E0_4();
extern "C" void _s803424E0_5();
extern "C" void _s803424E0_6();
extern "C" void _s803424E0_7();
extern "C" void _s803424E0_8();
extern "C" void _s803424E0_9();

struct ENgcRenderer {
    void WeightedBlend__GXPrimitive();
};

void ENgcRenderer::WeightedBlend__GXPrimitive() {
}
