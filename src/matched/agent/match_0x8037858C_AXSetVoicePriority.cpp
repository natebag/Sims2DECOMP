// 0x8037858C AXSetVoicePriority (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; bl _s8037858C_0; addi 31,3,0; addi 3,29,0; bl _s8037858C_1; lis 3,-32690; rlwinm 5,30,2,0,29; addi 0,3,-3232; add 4,0,5; lwz 3,0x0(4); li 0,0; stw 3,0x0(29); stw 0,0x4(29); lwz 0,0x0(29); cmplwi 0,0; beq 0f; lwz 3,0x0(4); stw 29,0x4(3); stw 29,0x0(4); b 1f; 0:; lis 3,-32690; addi 0,3,-3104; add 3,0,5; stw 29,0x0(3); stw 29,0x0(4); 1:; stw 30,0xc(29); mr 3,31; bl _s8037858C_2; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037858C_0();
extern "C" void _s8037858C_1();
extern "C" void _s8037858C_2();
extern "C" void f_8037858C() {}
