// 0x80359F38 EAllocGroup::DeallocateAll(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 31,0x4(30); b 1f; 0:; lwz 4,0x0(31); lwz 3,0xc(30); bl _s80359F38_0; lwz 31,0x4(31); 1:; li 0,1; cmpwi 31,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,30; bl _s80359F38_1; lwz 0,0x10(30); add 0,0,0; stw 0,0x14(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80359F38_0();
extern "C" void _s80359F38_1();
extern "C" void f_80359F38() {}
