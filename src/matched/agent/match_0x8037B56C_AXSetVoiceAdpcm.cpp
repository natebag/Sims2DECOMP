// 0x8037B56C AXSetVoiceAdpcm (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; addi 31,29,438; bl _s8037B56C_0; lwz 0,0x0(30); stw 0,0x0(31); lwz 0,0x4(30); stw 0,0x4(31); lwz 0,0x8(30); stw 0,0x8(31); lwz 0,0xc(30); stw 0,0xc(31); lwz 0,0x10(30); stw 0,0x10(31); lwz 0,0x14(30); stw 0,0x14(31); lwz 0,0x18(30); stw 0,0x18(31); lwz 0,0x1c(30); stw 0,0x1c(31); lwz 0,0x20(30); stw 0,0x20(31); lwz 0,0x24(30); stw 0,0x24(31); lwz 0,0x1c(29); oris 0,0,2; stw 0,0x1c(29); bl _s8037B56C_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037B56C_0();
extern "C" void _s8037B56C_1();
extern "C" void f_8037B56C() {}
