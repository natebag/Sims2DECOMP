// 0x80251828 __OSSetResetButtonTimer (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80251828_0; rlwinm 0,31,0,24,31; cmplwi 0,31; ble 0f; li 31,31; 0:; lis 4,-32768; lbz 0,0x30e3(4); rlwinm 0,0,0,0,26; stb 0,0x30e3(4); lbz 0,0x30e3(4); or 0,0,31; stb 0,0x30e3(4); bl _s80251828_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80251828_0();
extern "C" void _s80251828_1();
extern "C" void f_80251828() {}
