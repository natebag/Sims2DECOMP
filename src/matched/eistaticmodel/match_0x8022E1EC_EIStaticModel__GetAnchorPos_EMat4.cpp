// 0x8022E1EC EIStaticModel::GetAnchorPos(EMat4 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x80(3); lwz 12,0x84(3); addi 3,3,128; stw 11,0x0(4); stw 12,0x4(4); lwz 9,0x8(3); lwz 10,0xc(3); stw 9,0x8(4); stw 10,0xc(4); lwz 11,0x10(3); lwz 12,0x14(3); stw 11,0x10(4); stw 12,0x14(4); lwz 9,0x18(3); lwz 10,0x1c(3); stw 9,0x18(4); stw 10,0x1c(4); lwz 11,0x20(3); lwz 12,0x24(3); stw 11,0x20(4); stw 12,0x24(4); lwz 9,0x28(3); lwz 10,0x2c(3); stw 9,0x28(4); stw 10,0x2c(4); lwz 11,0x30(3); lwz 12,0x34(3); stw 11,0x30(4); stw 12,0x34(4); lwz 9,0x38(3); lwz 10,0x3c(3); stw 9,0x38(4); stw 10,0x3c(4)"

struct EIStaticModel {
    void GetAnchorPos_EMat4();
};

void EIStaticModel::GetAnchorPos_EMat4() {
}
