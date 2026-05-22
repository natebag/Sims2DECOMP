// 0x8026501C PADEnable (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); lis 0,-32768; stwu 1,-32(1); stw 31,0x1c(1); mr 31,3; srw 0,0,31; lwz 3,-23180(13); addi 4,1,12; or 0,3,0; stw 0,-23180(13); addi 3,31,0; bl _s8026501C_0; lwz 0,-27644(13); addi 3,31,0; oris 4,0,64; bl _s8026501C_1; lwz 3,-23180(13); bl _s8026501C_2; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8026501C_0();
extern "C" void _s8026501C_1();
extern "C" void _s8026501C_2();
extern "C" void f_8026501C() {}
