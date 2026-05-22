// 0x8031EE98 ERShader::CopyIntermediateShedData(EShaderDef (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 31,5; mr 4,31; li 5,1; mr 3,30; addi 31,31,1; bl _s8031EE98_0; addi 29,30,100; mr 4,31; li 5,1; addi 3,30,1; addi 31,31,1; bl _s8031EE98_1; li 28,2; mr 4,31; li 5,2; addi 3,30,2; addi 31,31,2; bl _s8031EE98_2; mr 4,31; li 5,4; addi 3,30,4; addi 31,31,4; bl _s8031EE98_3; mr 4,31; li 5,4; addi 3,30,8; addi 31,31,4; bl _s8031EE98_4; mr 4,31; li 5,4; addi 3,30,12; addi 31,31,4; bl _s8031EE98_5; mr 4,31; addi 3,30,16; li 5,48; addi 31,31,48; bl _s8031EE98_6; 0:; mr 3,29; mr 4,31; li 5,64; addi 31,31,64; bl _s8031EE98_7; addi 29,29,64; addic. 28,28,-1; bne 0b; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8031EE98_0();
extern "C" void _s8031EE98_1();
extern "C" void _s8031EE98_2();
extern "C" void _s8031EE98_3();
extern "C" void _s8031EE98_4();
extern "C" void _s8031EE98_5();
extern "C" void _s8031EE98_6();
extern "C" void _s8031EE98_7();
extern "C" void f_8031EE98() {}
