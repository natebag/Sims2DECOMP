// 0x80382298 CARDProbe (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32768; stw 0,0x4(1); stwu 1,-8(1); lbz 0,0x30e3(4); rlwinm. 0,0,0,24,24; beq 0f; li 3,0; b 1f; 0:; bl _s80382298_0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80382298_0();
extern "C" void f_80382298() {}
