// 0x80268618 DBGEXIInit (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,2; stw 0,0x4(1); addi 3,3,-32768; stwu 1,-8(1); bl _s80268618_0; lis 3,-13312; li 0,0; stw 0,0x6828(3); lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80268618_0();
extern "C" void f_80268618() {}
