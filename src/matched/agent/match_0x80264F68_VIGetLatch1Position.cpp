// 0x80264F68 __VIGetLatch1Position (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-13312; stw 0,0x4(1); addi 8,7,8192; addi 5,3,0; stwu 1,-8(1); addi 6,4,0; lhzu 0,0x44(8); rlwinm. 0,0,17,31,31; beq 0f; addi 7,7,8192; lhz 4,0x0(8); lhz 3,0x46(7); li 0,0; rlwinm 4,4,0,21,31; sth 0,0x0(8); rlwinm 3,3,0,21,31; sth 0,0x46(7); bl _s80264F68_0; li 3,1; b 1f; 0:; li 0,-1; sth 0,0x0(6); li 3,0; sth 0,0x0(5); 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80264F68_0();
extern "C" void f_80264F68() {}
