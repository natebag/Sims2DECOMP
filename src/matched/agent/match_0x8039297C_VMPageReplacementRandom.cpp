// 0x8039297C __VMPageReplacementRandom (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); stw 30,0x8(1); li 30,0; 0:; lwz 0,-25216(13); cmpwi 0,0; beq 1f; lwz 3,-21864(13); addi 0,3,1; mr 31,3; stw 0,-21864(13); bl _s8039297C_0; lwz 0,-21864(13); cmplw 0,3; blt 2f; stw 30,-25216(13); stw 30,-21864(13); b 2f; 1:; bl _s8039297C_1; mr 31,3; bl _s8039297C_2; divwu 0,3,31; mullw 0,0,31; subf 31,0,3; 2:; mr 3,31; bl _s8039297C_3; cmpwi 3,0; bne 0b; lwz 0,0x14(1); mr 3,31; lwz 31,0xc(1); lwz 30,0x8(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039297C_0();
extern "C" void _s8039297C_1();
extern "C" void _s8039297C_2();
extern "C" void _s8039297C_3();
extern "C" void f_8039297C() {}
