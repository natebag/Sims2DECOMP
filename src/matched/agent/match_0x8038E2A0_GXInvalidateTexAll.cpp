// 0x8038E2A0 GXInvalidateTexAll (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8038E2A0_0; li 6,97; lis 3,26112; lis 5,-13311; stb 6,-32768(5); addi 4,3,4096; addi 0,3,4352; stw 4,-32768(5); stb 6,-32768(5); stw 0,-32768(5); bl _s8038E2A0_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038E2A0_0();
extern "C" void _s8038E2A0_1();
extern "C" void f_8038E2A0() {}
