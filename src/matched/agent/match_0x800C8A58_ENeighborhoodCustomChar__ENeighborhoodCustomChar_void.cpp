// 0x800C8A58 ENeighborhoodCustomChar::ENeighborhoodCustomChar(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,0; addi 3,31,20; bl _s800C8A58_0; li 8,4; li 0,0; li 9,0; mtspr 9,8; stw 0,0x174(31); li 10,0; stb 9,0xc(31); addi 11,31,388; sth 9,0x0(31); sth 9,0x2(31); sth 9,0x4(31); sth 9,0x6(31); sth 9,0x8(31); sth 9,0xa(31); stw 0,0x10(31); stw 0,0x138(31); stw 0,0x13c(31); stw 0,0x140(31); stw 0,0x144(31); stw 0,0x148(31); stw 0,0x14c(31); stw 0,0x150(31); stw 0,0x154(31); stw 0,0x158(31); stw 0,0x15c(31); stw 0,0x160(31); stw 0,0x164(31); stw 0,0x168(31); stw 0,0x16c(31); stw 0,0x170(31); 0:; stw 10,0x0(11); addi 11,11,-4; bdnz 0b; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800C8A58_0();
extern "C" void f_800C8A58() {}
