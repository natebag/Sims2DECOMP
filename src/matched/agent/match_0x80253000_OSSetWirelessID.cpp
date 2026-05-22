// 0x80253000 OSSetWirelessID (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32694; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,-24704; stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s80253000_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s80253000_1; li 3,0; b 1f; 0:; stw 3,0x44(31); li 0,1; addi 3,31,20; stw 0,0x0(4); 1:; rlwinm 0,29,1,0,30; add 4,3,0; lhzu 3,0x1c(4); rlwinm 0,30,0,16,31; cmplw 3,0; beq 2f; sth 30,0x0(4); li 3,1; li 4,20; bl _s80253000_2; b 3f; 2:; li 3,0; li 4,20; bl _s80253000_3; 3:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80253000_0();
extern "C" void _s80253000_1();
extern "C" void _s80253000_2();
extern "C" void _s80253000_3();
extern "C" void f_80253000() {}
