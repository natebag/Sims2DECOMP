// 0x80266D18 __PADDisableRecalibration (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80266D18_0; lis 4,-32768; lbz 0,0x30e3(4); rlwinm. 0,0,0,25,25; beq 0f; li 31,1; b 1f; 0:; li 31,0; 1:; lis 4,-32768; lbz 0,0x30e3(4); cmpwi 30,0; rlwinm 0,0,0,26,24; stb 0,0x30e3(4); beq 2f; lbz 0,0x30e3(4); ori 0,0,64; stb 0,0x30e3(4); 2:; bl _s80266D18_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80266D18_0();
extern "C" void _s80266D18_1();
extern "C" void f_80266D18() {}
