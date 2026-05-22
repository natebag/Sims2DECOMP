// 0x803905A4 GXCallDisplayList (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; lwz 5,-17720(13); lwz 0,0x5ac(5); cmplwi 0,0; beq 0f; bl _s803905A4_0; 0:; lwz 3,-17720(13); lwz 0,0x0(3); cmplwi 0,0; bne 1f; bl _s803905A4_1; 1:; li 0,64; lis 3,-13311; stb 0,-32768(3); stw 30,-32768(3); stw 31,-32768(3); lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803905A4_0();
extern "C" void _s803905A4_1();
extern "C" void f_803905A4() {}
