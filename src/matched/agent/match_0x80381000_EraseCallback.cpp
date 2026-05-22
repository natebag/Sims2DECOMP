// 0x80381000 EraseCallback (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,3,0; lis 3,-32688; stw 30,0x20(1); mulli 5,31,272; stw 29,0x1c(1); addi 0,3,-24000; mr. 29,4; add 30,0,5; blt 0f; lwz 5,0x84(30); lis 3,-32712; lwz 0,0x80(30); addi 7,3,3888; lwz 3,0xc(30); subf 0,0,5; rlwinm 0,0,19,13,31; mullw 4,3,0; addi 6,5,0; addi 3,31,0; li 5,8192; bl _s80381000_0; mr. 29,3; bge 2f; 0:; lwz 0,0xd0(30); cmplwi 0,0; bne 1f; addi 3,30,0; addi 4,29,0; bl _s80381000_1; 1:; lwz 0,0xd8(30); cmplwi 0,0; mr 12,0; beq 2f; li 0,0; mtspr 8,12; stw 0,0xd8(30); addi 3,31,0; addi 4,29,0; blrl; 2:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80381000_0();
extern "C" void _s80381000_1();
extern "C" void f_80381000() {}
