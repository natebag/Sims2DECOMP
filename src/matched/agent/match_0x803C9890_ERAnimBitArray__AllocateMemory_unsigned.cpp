// 0x803C9890 ERAnimBitArray::AllocateMemory(unsigned (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32693; li 5,8; addi 3,3,11064; bl _s803C9890_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803C9890_0();
extern "C" void f_803C9890() {}
