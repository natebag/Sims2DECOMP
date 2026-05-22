// 0x80377FB0 __AXInitVoiceStacks (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-22288(13); li 0,2; lis 4,-32690; mtspr 9,0; lis 3,-32690; addi 4,4,-3104; addi 3,3,-3232; 0:; li 0,0; stw 0,0x0(4); stw 0,0x0(3); stw 0,0x4(4); stw 0,0x4(3); stw 0,0x8(4); stw 0,0x8(3); stw 0,0xc(4); stw 0,0xc(3); stw 0,0x10(4); stw 0,0x10(3); stw 0,0x14(4); stw 0,0x14(3); stw 0,0x18(4); stw 0,0x18(3); stw 0,0x1c(4); stw 0,0x1c(3); stw 0,0x20(4); stw 0,0x20(3); stw 0,0x24(4); stw 0,0x24(3); stw 0,0x28(4); stw 0,0x28(3); stw 0,0x2c(4); stw 0,0x2c(3); stw 0,0x30(4); stw 0,0x30(3); stw 0,0x34(4); stw 0,0x34(3); stw 0,0x38(4); stw 0,0x38(3); stw 0,0x3c(4); addi 4,4,64; stw 0,0x3c(3); addi 3,3,64; bdnz 0b"
extern "C" void f_80377FB0() {}
