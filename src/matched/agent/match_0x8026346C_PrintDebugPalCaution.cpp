// 0x8026346C PrintDebugPalCaution (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32700; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,3,-12696; lwz 0,-23192(13); cmplwi 0,0; bne 0f; li 0,1; crxor 6,6,6; stw 0,-23192(13); addi 3,31,624; bl _s8026346C_0; addi 3,31,668; crxor 6,6,6; bl _s8026346C_1; addi 3,31,712; crxor 6,6,6; bl _s8026346C_2; addi 3,31,756; crxor 6,6,6; bl _s8026346C_3; addi 3,31,800; crxor 6,6,6; bl _s8026346C_4; addi 3,31,844; crxor 6,6,6; bl _s8026346C_5; addi 3,31,624; crxor 6,6,6; bl _s8026346C_6; 0:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8026346C_0();
extern "C" void _s8026346C_1();
extern "C" void _s8026346C_2();
extern "C" void _s8026346C_3();
extern "C" void _s8026346C_4();
extern "C" void _s8026346C_5();
extern "C" void _s8026346C_6();
extern "C" void f_8026346C() {}
