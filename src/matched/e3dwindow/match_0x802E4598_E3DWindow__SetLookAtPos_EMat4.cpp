// 0x802E4598 E3DWindow::SetLookAtPos(EMat4 (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 8,4; mr 30,3; lwz 11,0x0(8); lwz 12,0x4(8); addi 7,30,224; addi 3,30,160; stw 11,0xe0(30); stw 12,0xe4(30); lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x8(7); stw 10,0xc(7); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x10(7); stw 12,0x14(7); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x18(7); stw 10,0x1c(7); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x20(7); stw 12,0x24(7); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x28(7); stw 10,0x2c(7); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x30(7); stw 12,0x34(7); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x38(7); stw 10,0x3c(7); bl _s802E4598_0; mr 3,30; bl _s802E4598_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802E4598_0();
extern "C" void _s802E4598_1();

struct E3DWindow {
    void SetLookAtPos();
};

void E3DWindow::SetLookAtPos() {
}
