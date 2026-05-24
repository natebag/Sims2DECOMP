// 0x8034420C ENgcRenderer::ViewMatrix(EDLEntry (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,0x4(4); mr 30,3; lwz 10,0x4d8(30); addi 4,30,948; lfs f0,0x0(11); addi 8,11,16; addi 9,10,2144; addi 7,11,32; stfs f0,0x860(10); addi 6,11,48; lfs f0,0x10(11); stfs f0,0x4(9); lfs f13,0x20(11); stfs f13,0x8(9); lfs f0,0x30(11); stfs f0,0xc(9); lfs f13,0x4(11); stfs f13,0x10(9); lfs f0,0x4(8); stfs f0,0x14(9); lfs f13,0x4(7); stfs f13,0x18(9); lfs f0,0x4(6); stfs f0,0x1c(9); lfs f13,0x8(11); stfs f13,0x20(9); lfs f0,0x8(8); stfs f0,0x24(9); lfs f13,0x8(7); stfs f13,0x28(9); lfs f0,0x8(6); stfs f0,0x2c(9); lwz 3,0x4d8(30); addi 3,3,2144; bl _s8034420C_0; lwz 9,0x4d8(30); li 11,1; lwz 0,0x6cc(9); oris 0,0,32768; ori 0,0,4; stw 0,0x6cc(9); stw 11,0x510(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8034420C_0();

struct ENgcRenderer {
    void ViewMatrix_EDLEntry();
};

void ENgcRenderer::ViewMatrix_EDLEntry() {
}
