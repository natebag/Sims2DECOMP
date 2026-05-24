// 0x802E5DA0 E3DWindow::ProjectionMatrixChanged(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; li 4,4; lwz 9,0x160(30); lwz 10,0x164(30); addi 7,30,352; addi 8,30,416; addi 5,30,432; stw 9,0x1a0(30); stw 10,0x1a4(30); addi 0,30,448; addi 6,30,464; addi 3,1,8; lwz 9,0x8(7); lwz 10,0xc(7); stw 9,0x8(8); stw 10,0xc(8); lwz 11,0x10(7); lwz 12,0x14(7); stw 11,0x10(8); stw 12,0x14(8); lwz 9,0x18(7); lwz 10,0x1c(7); stw 9,0x18(8); stw 10,0x1c(8); lwz 11,0x20(7); lwz 12,0x24(7); stw 11,0x20(8); stw 12,0x24(8); lwz 9,0x28(7); lwz 10,0x2c(7); stw 9,0x28(8); stw 10,0x2c(8); lwz 11,0x30(7); lwz 12,0x34(7); stw 11,0x30(8); stw 12,0x34(8); lwz 9,0x38(7); lwz 10,0x3c(7); stw 9,0x38(8); stw 10,0x3c(8); stw 8,0x8(1); stw 5,0xc(1); stw 0,0x10(1); stw 6,0x14(1); bl _s802E5DA0_0; mr 3,30; bl _s802E5DA0_1; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s802E5DA0_0();
extern "C" void _s802E5DA0_1();

struct E3DWindow {
    void ProjectionMatrixChanged();
};

void E3DWindow::ProjectionMatrixChanged() {
}
