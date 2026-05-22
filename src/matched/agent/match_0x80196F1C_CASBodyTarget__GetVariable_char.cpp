// 0x80196F1C CASBodyTarget::GetVariable(char (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,32; bl _s80196F1C_0; li 0,0; stb 0,0x0(3); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80196F1C_0();
extern "C" void f_80196F1C() {}
