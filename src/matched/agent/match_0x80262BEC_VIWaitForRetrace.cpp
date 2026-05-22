// 0x80262BEC VIWaitForRetrace (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); stw 30,0x8(1); bl _s80262BEC_0; lwz 30,-23284(13); mr 31,3; 0:; addi 3,13,-23276; bl _s80262BEC_1; lwz 0,-23284(13); cmplw 30,0; beq 0b; mr 3,31; bl _s80262BEC_2; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80262BEC_0();
extern "C" void _s80262BEC_1();
extern "C" void _s80262BEC_2();
extern "C" void f_80262BEC() {}
