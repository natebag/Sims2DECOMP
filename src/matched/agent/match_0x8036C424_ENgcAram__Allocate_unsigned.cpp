// 0x8036C424 ENgcAram::Allocate(unsigned (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8036C424_0; cmplw 3,31; li 3,-1; blt 0f; lwz 3,-25824(13); add 0,3,31; stw 0,-25824(13); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8036C424_0();
extern "C" void f_8036C424() {}
