// 0x80142EAC SpriteSlot::SpriteSlot(SlotDescriptor (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; bl _s80142EAC_0; lis 9,-32698; lwz 3,-21432(13); addi 9,9,18928; mr 4,28; stw 9,0x0(30); lfs f0,0x4(29); stfs f0,0x4(30); lfs f13,0x8(29); stfs f13,0x8(30); lfs f0,0xc(29); stw 28,0x64(30); stfs f0,0xc(30); bl _s80142EAC_1; li 0,0; li 11,-1; li 9,400; stw 0,0x60(30); stw 9,0x20(30); mr 3,30; stw 11,0x40(30); stw 0,0x18(30); stw 0,0x1c(30); stw 0,0x24(30); stw 0,0x28(30); stw 0,0x30(30); stw 0,0x10(30); stw 0,0x44(30); stw 11,0x3c(30); lfs f0,0xc(29); stfs f0,0x4c(30); bl _s80142EAC_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80142EAC_0();
extern "C" void _s80142EAC_1();
extern "C" void _s80142EAC_2();

struct SpriteSlot {
    void SpriteSlot_SlotDescriptor();
};

void SpriteSlot::SpriteSlot_SlotDescriptor() {
}
