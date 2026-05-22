// 0x80382244 __CARDDisable (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80382244_0; lis 4,-32768; lbz 0,0x30e3(4); cmpwi 31,0; rlwinm 0,0,0,25,23; stb 0,0x30e3(4); beq 0f; lbz 0,0x30e3(4); ori 0,0,128; stb 0,0x30e3(4); 0:; bl _s80382244_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80382244_0();
extern "C" void _s80382244_1();
extern "C" void f_80382244() {}
