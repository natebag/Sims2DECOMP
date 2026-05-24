// 0x80345120 ENgcRenderer::Material(EDLEntry (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(4); addi 8,3,1304; addi 10,3,1320; addi 6,3,1336; lfs f0,0x0(9); addi 11,9,16; addi 7,9,32; li 5,1; stfs f0,0x518(3); lfs f0,0x4(9); stfs f0,0x4(8); lfs f13,0x8(9); stfs f13,0x8(8); lfs f0,0xc(9); stfs f0,0xc(8); lfs f13,0x10(9); stfs f13,0x528(3); lfs f0,0x4(11); stfs f0,0x4(10); lfs f13,0x8(11); stfs f13,0x8(10); lfs f0,0xc(11); stfs f0,0xc(10); lwz 0,0x20(9); lwz 11,0x8(7); lwz 10,0x4(7); stw 0,0x538(3); stw 11,0x8(6); stw 10,0x4(6); lfs f0,0x2c(9); stfs f0,0x2c(8); stw 5,0x510(3)"

struct ENgcRenderer {
    void Material_EDLEntry();
};

void ENgcRenderer::Material_EDLEntry() {
}
