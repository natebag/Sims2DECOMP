// 0x8019C1B4 CASMiscTarget::GetVariable(char (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,32; bl _s8019C1B4_0; li 0,0; stb 0,0x0(3); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8019C1B4_0();
extern "C" void f_8019C1B4() {}
