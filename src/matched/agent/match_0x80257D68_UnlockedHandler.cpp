// 0x80257D68 UnlockedHandler (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); li 4,0; addi 5,1,16; bl _s80257D68_0; lwz 0,0x1c(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80257D68_0();
extern "C" void f_80257D68() {}
