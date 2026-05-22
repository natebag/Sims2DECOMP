// 0x800A0418 operator!=(BString2 (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 5,0; li 6,1; bl _s800A0418_0; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A0418_0();
extern "C" void f_800A0418() {}
