// 0x80250980 MEMIntrruptHandler (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 8,3,16384; li 0,0; stwu 1,-8(1); lhz 7,0x4024(3); lis 3,-32694; lhz 6,0x22(8); addi 3,3,-24784; lhz 5,0x1e(8); rlwimi 6,7,16,6,15; sth 0,0x20(8); lwz 12,0x3c(3); cmplwi 12,0; beq 0f; mtspr 8,12; li 3,15; crxor 6,6,6; blrl; b 1f; 0:; li 3,15; bl _s80250980_0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80250980_0();
extern "C" void f_80250980() {}
