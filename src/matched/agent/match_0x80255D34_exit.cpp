// 0x80255D34 exit (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lis 3,-32700; addi 31,3,11864; b 0f; 0:; b 1f; 1:; b 3f; 2:; mtspr 8,12; blrl; addi 31,31,4; 3:; lwz 12,0x0(31); cmplwi 12,0; bne 2b; bl _s80255D34_0; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80255D34_0();
extern "C" void f_80255D34() {}
