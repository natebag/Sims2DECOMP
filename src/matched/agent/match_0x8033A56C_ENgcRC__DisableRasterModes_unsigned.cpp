// 0x8033A56C ENgcRC::DisableRasterModes(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); not 4,4; li 0,22; lis 3,-32691; stw 4,0xc(1); stb 0,0x8(1); addi 3,3,21688; stb 5,0x9(1); addi 4,1,8; bl _s8033A56C_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8033A56C_0();
extern "C" void f_8033A56C() {}
