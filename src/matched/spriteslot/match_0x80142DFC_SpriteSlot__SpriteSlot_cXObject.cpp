// 0x80142DFC SpriteSlot::SpriteSlot(cXObject (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; bl _s80142DFC_0; lis 9,-32706; lis 11,-32698; lfs f31,-10500(9); addi 11,11,18928; lwz 3,-21432(13); mr 4,29; stw 29,0x64(30); stfs f31,0x4(30); stfs f31,0x8(30); stfs f31,0xc(30); stw 11,0x0(30); bl _s80142DFC_1; li 0,0; li 11,-1; li 9,400; stfs f31,0x4c(30); mr 3,30; stw 9,0x20(30); stw 0,0x60(30); stw 11,0x40(30); stw 0,0x18(30); stw 0,0x1c(30); stw 0,0x24(30); stw 0,0x28(30); stw 0,0x30(30); stw 0,0x10(30); stw 0,0x44(30); stw 11,0x3c(30); bl _s80142DFC_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s80142DFC_0();
extern "C" void _s80142DFC_1();
extern "C" void _s80142DFC_2();

struct SpriteSlot {
    void SpriteSlot_cXObject();
};

void SpriteSlot::SpriteSlot_cXObject() {
}
