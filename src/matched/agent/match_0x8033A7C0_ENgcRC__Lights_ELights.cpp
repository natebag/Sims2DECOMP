// 0x8033A7C0 ENgcRC::Lights(ELights (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr. 9,4; li 10,0; beq 0f; lwz 10,0xf0(9); 0:; li 11,0; beq 1f; lwz 11,0xf4(9); 1:; li 0,24; lis 3,-32691; stb 0,0x8(1); addi 3,3,21688; stb 10,0x9(1); addi 4,1,8; stb 11,0xa(1); stw 9,0xc(1); bl _s8033A7C0_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8033A7C0_0();
extern "C" void f_8033A7C0() {}
