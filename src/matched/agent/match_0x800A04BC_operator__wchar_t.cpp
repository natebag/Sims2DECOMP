// 0x800A04BC operator<(wchar_t, (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; li 5,0; mr 3,4; li 6,1; mr 4,0; bl _s800A04BC_0; cmpwi 3,0; li 3,1; bgt 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A04BC_0();
extern "C" void f_800A04BC() {}
