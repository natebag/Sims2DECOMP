// 0x80351F84 Effects::Effect::DefaultInit(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 10,0x4(3); li 0,3332; lwz 11,0x8(3); lwz 12,0xc(3); addi 8,3,256; stw 9,0x100(3); stw 10,0x104(3); stw 0,0x140(3); stw 11,0x8(8); stw 12,0xc(8); lwz 9,0x10(3); lwz 10,0x14(3); stw 9,0x10(8); stw 10,0x14(8); lwz 11,0x18(3); lwz 12,0x1c(3); stw 11,0x18(8); stw 12,0x1c(8); lwz 9,0x20(3); lwz 10,0x24(3); stw 9,0x20(8); stw 10,0x24(8); lwz 11,0x28(3); lwz 12,0x2c(3); stw 11,0x28(8); stw 12,0x2c(8); lwz 9,0x30(3); lwz 10,0x34(3); stw 9,0x30(8); stw 10,0x34(8); lwz 11,0x38(3); lwz 12,0x3c(3); stw 11,0x38(8); stw 12,0x3c(8)"

struct Effects {
    void Effect__DefaultInit();
};

void Effects::Effect__DefaultInit() {
}
