// 0x80392274 __VMAllocMRAMSwapSpace (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s80392274_0; lwz 0,-21896(13); stw 3,-21892(13); add 3,3,0; bl _s80392274_1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392274_0();
extern "C" void _s80392274_1();
extern "C" void f_80392274() {}
