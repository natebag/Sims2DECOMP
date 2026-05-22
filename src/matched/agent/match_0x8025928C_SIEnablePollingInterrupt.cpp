// 0x8025928C SIEnablePollingInterrupt (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); addi 31,4,-21872; stw 30,0x28(1); stw 29,0x24(1); addi 29,3,0; bl _s8025928C_0; lis 4,-13312; lwzu 5,0x6434(4); rlwinm. 0,5,0,4,4; beq 0f; li 30,1; b 1f; 0:; li 30,0; 1:; cmpwi 29,0; beq 2f; li 0,0; stw 0,0x1e0(31); oris 5,5,2048; stw 0,0x1e4(31); stw 0,0x1e8(31); stw 0,0x1ec(31); b 3f; 2:; rlwinm 5,5,0,5,3; 3:; rlwinm 5,5,0,1,30; stw 5,0x0(4); bl _s8025928C_1; mr 3,30; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8025928C_0();
extern "C" void _s8025928C_1();
extern "C" void f_8025928C() {}
