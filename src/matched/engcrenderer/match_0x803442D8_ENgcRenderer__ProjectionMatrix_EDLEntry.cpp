// 0x803442D8 ENgcRenderer::ProjectionMatrix(EDLEntry (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(4); lis 10,-32688; addi 11,10,-12212; li 0,2; lfs f0,0x0(9); addi 8,9,16; addi 7,9,32; addi 6,9,48; stfs f0,-12212(10); li 10,1; lfs f0,0x10(9); stfs f0,0x4(11); lfs f13,0x20(9); stfs f13,0x8(11); lfs f0,0x30(9); stfs f0,0xc(11); lfs f13,0x4(9); stfs f13,0x10(11); lfs f0,0x4(8); stfs f0,0x14(11); lfs f13,0x4(7); stfs f13,0x18(11); lfs f0,0x4(6); stfs f0,0x1c(11); lfs f13,0x8(9); stfs f13,0x20(11); lfs f0,0x8(8); stfs f0,0x24(11); lfs f13,0x8(7); stfs f13,0x28(11); lfs f0,0x8(6); stfs f0,0x2c(11); lfs f13,0xc(9); stfs f13,0x30(11); lfs f0,0xc(8); stfs f0,0x34(11); lfs f13,0xc(7); stfs f13,0x38(11); lfs f0,0xc(6); stfs f0,0x3c(11); lwz 9,0x4d8(3); stw 0,0x9d8(9); lwz 11,0x4d8(3); lwz 0,0x6cc(11); oris 0,0,32768; ori 0,0,32; stw 0,0x6cc(11); stw 10,0x510(3)"

struct ENgcRenderer {
    void ProjectionMatrix_EDLEntry();
};

void ENgcRenderer::ProjectionMatrix_EDLEntry() {
}
