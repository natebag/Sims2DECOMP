// 0x80261334 WaitBeforeRead (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 9,-32694; stw 0,0x4(1); li 0,1; stwu 1,-48(1); stw 31,0x2c(1); addi 31,9,-16952; li 9,-1; stw 30,0x28(1); addi 30,7,0; stw 29,0x24(1); addi 29,8,0; stw 0,0x0(31); li 0,0; stw 3,0x4(31); addi 3,31,64; stw 4,0x8(31); stw 5,0xc(31); stw 6,0x10(31); stw 9,0x14(31); stw 0,-23292(13); bl _s80261334_0; lis 3,-32730; addi 7,3,3904; addi 6,29,0; addi 5,30,0; addi 3,31,64; bl _s80261334_1; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80261334_0();
extern "C" void _s80261334_1();
extern "C" void f_80261334() {}
