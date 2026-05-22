// 0x80359FF8 EAllocGroup::RemoveAllocExternal(void (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80359FF8_0; mr. 4,3; beq 0f; mr 3,31; bl _s80359FF8_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80359FF8_0();
extern "C" void _s80359FF8_1();
extern "C" void f_80359FF8() {}
