// 0x8031C280 LoadXImage(EFile (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 6,4; li 0,0; stw 0,0x8(1); li 4,0; addi 5,1,8; bl _s8031C280_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8031C280_0();
extern "C" void f_8031C280() {}
