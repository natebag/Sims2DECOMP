// 0x80142A28 RoutingSlot::RoutingSlot(SlotDescriptor (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80142A28_0; lis 9,-32698; mr 3,30; addi 9,9,18896; stw 9,0x0(30); lfs f0,0x4(29); stfs f0,0x4(30); lfs f13,0x8(29); stfs f13,0x8(30); lfs f0,0xc(29); stfs f0,0xc(30); lwz 0,0x28(29); stw 0,0x1c(30); lwz 9,0x1c(29); stw 9,0x10(30); lwz 0,0x20(29); stw 0,0x14(30); lwz 9,0x24(29); stw 9,0x18(30); lwz 0,0x2c(29); stw 0,0x20(30); lwz 9,0x30(29); stw 9,0x24(30); lwz 0,0x34(29); stw 0,0x28(30); lwz 9,0x38(29); stw 9,0x2c(30); lfs f0,0x3c(29); stfs f0,0x30(30); lwz 0,0x40(29); stw 0,0x34(30); lwz 9,0x44(29); stw 9,0x38(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80142A28_0();

struct RoutingSlot {
    void RoutingSlot_SlotDescriptor();
};

void RoutingSlot::RoutingSlot_SlotDescriptor() {
}
