// 0x80366664 BIG_pointer(void (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); stw 4,0x8(1); mr 31,3; li 4,0; addi 5,1,8; addi 6,1,12; li 7,0; bl _s80366664_0; cmpwi 3,0; li 3,0; beq 0f; lwz 3,0xc(1); add 3,31,3; 0:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80366664_0();
extern "C" void f_80366664() {}
