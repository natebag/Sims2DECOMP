// 0x80252F7C OSGetWirelessID (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,-24704; stw 30,0x18(1); addi 30,3,0; bl _s80252F7C_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s80252F7C_1; li 3,0; b 1f; 0:; stw 3,0x44(31); li 0,1; addi 3,31,20; stw 0,0x0(4); 1:; rlwinm 0,30,1,0,30; add 3,3,0; lhz 31,0x1c(3); li 3,0; li 4,20; bl _s80252F7C_2; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80252F7C_0();
extern "C" void _s80252F7C_1();
extern "C" void _s80252F7C_2();
extern "C" void f_80252F7C() {}
