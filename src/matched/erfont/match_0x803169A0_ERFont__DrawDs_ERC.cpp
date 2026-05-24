// 0x803169A0 ERFont::DrawDs(ERC (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 19,0x5c(1); stw 0,0x94(1); lis 11,-32702; mr 26,3; lfs f0,0x744(11); mr 23,4; mr 22,5; mr 25,6; mr 21,7; mr 20,8; mr 24,9; mr 19,10; fcmpu 0,f1,f0; bge 0f; fmr f1,f0; b 1f; 0:; fmr f0,f1; fctiwz f13,f0; mr 11,9; stfd f13,0x50(1); lis 0,17200; lis 10,-32702; lwz 9,0x54(1); lfd f13,0x748(10); xoris 9,9,32768; stw 9,0x54(1); stw 0,0x50(1); lfd f0,0x50(1); fsub f0,f0,f13; frsp f1,f0; 1:; lwz 11,-26392(13); lis 5,17200; mr 6,8; lwz 0,0x18(11); lis 10,-32702; lwz 9,0x1c(11); lis 7,-32702; xoris 0,0,32768; lfd f10,0x748(10); stw 0,0x54(1); xoris 9,9,32768; lfs f12,0x744(7); addi 30,26,88; stw 5,0x50(1); addi 31,1,24; lfs f4,0x0(25); lis 11,-32702; lfd f0,0x50(1); addi 28,1,56; stw 9,0x54(1); li 29,0; fsub f0,f0,f10; lfs f5,0x4(25); stw 5,0x50(1); frsp f0,f0; fdivs f0,f12,f0; lfs f6,0x58(26); lfd f13,0x50(1); addi 27,1,32; lfs f7,0x4(30); mr 3,26; lfs f8,0x8(30); mr 4,23; lfs f9,0xc(30); mr 5,22; lfs f11,0x750(11); li 6,0; mr 7,27; mr 8,21; mr 9,20; li 10,0; fsub f13,f13,f10; stfs f0,0x20(1); frsp f13,f13; fdivs f12,f12,f13; stfs f12,0x24(1); fmadds f0,f1,f0,f4; fmuls f12,f1,f12; stfs f0,0x18(1); stfs f12,0x1c(1); lfs f0,0x4(31); fadds f0,f0,f5; stfs f0,0x4(31); stfs f11,0x38(1); stfs f6,0x28(1); stfs f7,0x2c(1); stfs f8,0x30(1); stfs f9,0x34(1); stfs f11,0x8(28); stfs f11,0x4(28); stfs f2,0x44(1); lfs f0,0x38(1); lfs f13,0x3c(1); lfs f12,0x40(1); stfs f0,0x58(26); lfs f11,0x18(1); stfs f13,0x4(30); stfs f12,0x8(30); stfs f2,0xc(30); stfs f11,0x20(1); lfs f0,0x4(31); stw 29,0x8(1); stfs f0,0x24(1); stw 29,0xc(1); stw 29,0x10(1); stw 19,0x14(1); bl _s803169A0_0; lfs f13,0x28(1); mr 3,26; lfs f0,0x34(1); mr 4,23; lfs f12,0x2c(1); mr 5,22; lfs f11,0x30(1); mr 7,27; stfs f13,0x58(26); mr 8,21; stfs f0,0xc(30); mr 9,20; stfs f12,0x4(30); li 6,0; stfs f11,0x8(30); mr 10,31; stw 29,0x10(1); lfs f0,0x4(25); lfs f13,0x0(25); stfs f0,0x24(1); stfs f13,0x20(1); stw 19,0x14(1); stw 29,0x8(1); stw 29,0xc(1); bl _s803169A0_1; cmpwi 24,0; beq 2f; lwz 0,0x4(31); lwz 9,0x18(1); stw 0,0x4(24); stw 9,0x0(24); 2:; lwz 0,0x94(1); mtspr 8,0; lmw 19,0x5c(1); addi 1,1,144"

extern "C" void _s803169A0_0();
extern "C" void _s803169A0_1();

struct ERFont {
    void DrawDs();
};

void ERFont::DrawDs() {
}
