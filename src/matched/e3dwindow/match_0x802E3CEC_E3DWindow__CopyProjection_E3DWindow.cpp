// 0x802E3CEC E3DWindow::CopyProjection(E3DWindow (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lfs f13,0x28c(4); mr 8,3; addi 7,4,352; addi 6,8,352; stfs f13,0x28c(8); lfs f0,0x29c(4); stfs f0,0x29c(8); lfs f13,0x2f0(4); stfs f13,0x2f0(8); lfs f0,0x2f4(4); stfs f0,0x2f4(8); lfs f13,0x2f8(4); stfs f13,0x2f8(8); lwz 9,0x160(4); lwz 10,0x164(4); stw 9,0x160(8); stw 10,0x164(8); lwz 11,0x8(7); lwz 12,0xc(7); stw 11,0x8(6); stw 12,0xc(6); lwz 9,0x10(7); lwz 10,0x14(7); stw 9,0x10(6); stw 10,0x14(6); lwz 11,0x18(7); lwz 12,0x1c(7); stw 11,0x18(6); stw 12,0x1c(6); lwz 9,0x20(7); lwz 10,0x24(7); stw 9,0x20(6); stw 10,0x24(6); lwz 11,0x28(7); lwz 12,0x2c(7); stw 11,0x28(6); stw 12,0x2c(6); lwz 9,0x30(7); lwz 10,0x34(7); stw 9,0x30(6); stw 10,0x34(6); lwz 11,0x38(7); lwz 12,0x3c(7); stw 11,0x38(6); stw 12,0x3c(6); bl _s802E3CEC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802E3CEC_0();

struct E3DWindow {
    void CopyProjection_E3DWindow();
};

void E3DWindow::CopyProjection_E3DWindow() {
}
