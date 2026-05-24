// 0x80317A48 ERFont::Draw(ERC (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lfs f0,0x0(6); mr 0,7; lfs f13,0x4(6); mr 11,8; mr 6,9; lwz 28,0x38(1); addi 9,1,24; lwz 30,0x3c(1); lwz 29,0x40(1); mr 7,9; stw 10,0x8(1); mr 8,0; stfs f0,0x18(1); mr 10,6; stfs f13,0x4(9); li 6,1; mr 9,11; stw 28,0xc(1); stw 30,0x10(1); stw 29,0x14(1); bl _s80317A48_0; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"

extern "C" void _s80317A48_0();

struct ERFont {
    void Draw();
};

void ERFont::Draw() {
}
