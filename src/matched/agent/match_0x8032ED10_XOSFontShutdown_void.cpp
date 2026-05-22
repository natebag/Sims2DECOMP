// 0x8032ED10 XOSFontShutdown(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26448(13); cmpwi 0,0; beq 0f; bl _s8032ED10_0; lwz 4,-26448(13); bl _s8032ED10_1; li 0,0; stw 0,-26448(13); 0:; li 0,0; stw 0,-26440(13); stw 0,-26436(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032ED10_0();
extern "C" void _s8032ED10_1();
extern "C" void f_8032ED10() {}
