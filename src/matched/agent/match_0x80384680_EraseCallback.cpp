// 0x80384680 EraseCallback (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr. 29,4; stw 28,0x10(1); addi 28,3,0; mulli 5,28,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; blt 0f; lwz 4,0xc0(31); lis 3,-32712; addi 7,3,17680; lwz 5,0xc(31); lhz 0,0x10(4); lwz 6,0xb4(31); addi 3,28,0; mullw 4,5,0; bl _s80384680_0; mr. 29,3; bge 1f; 0:; lwz 30,0xd0(31); li 0,0; addi 3,31,0; stw 0,0xd0(31); mr 4,29; bl _s80384680_1; addi 12,30,0; mtspr 8,12; addi 3,28,0; addi 4,29,0; blrl; 1:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80384680_0();
extern "C" void _s80384680_1();
extern "C" void f_80384680() {}
