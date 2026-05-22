// 0x80392A10 __VMPageReplacementFIFO (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); li 31,0; stw 30,0x8(1); 0:; lwz 3,-21864(13); addi 0,3,1; mr 30,3; stw 0,-21864(13); bl _s80392A10_0; lwz 0,-21864(13); cmplw 0,3; blt 1f; stw 31,-25216(13); stw 31,-21864(13); 1:; mr 3,30; bl _s80392A10_1; cmpwi 3,0; bne 0b; lwz 0,0x14(1); mr 3,30; lwz 31,0xc(1); lwz 30,0x8(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392A10_0();
extern "C" void _s80392A10_1();
extern "C" void f_80392A10() {}
