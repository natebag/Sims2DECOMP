// 0x8031ED68 ERShader::CopyShedData(EShaderDef (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,4; mr 31,5; mr 4,31; li 5,1; mr 3,30; addi 31,31,1; bl _s8031ED68_0; li 28,0; mr 4,31; li 5,1; addi 3,30,1; addi 31,31,1; bl _s8031ED68_1; addi 29,30,64; mr 4,31; li 5,2; addi 3,30,2; addi 31,31,2; bl _s8031ED68_2; mr 4,31; li 5,4; addi 3,30,4; addi 31,31,4; bl _s8031ED68_3; mr 4,31; li 5,4; addi 3,30,8; addi 31,31,4; bl _s8031ED68_4; mr 4,31; li 5,4; addi 3,30,12; addi 31,31,4; bl _s8031ED68_5; mr 4,31; addi 3,30,16; li 5,48; addi 31,31,48; bl _s8031ED68_6; 0:; mr 3,29; mr 4,31; li 5,4; addi 28,28,1; bl _s8031ED68_7; addi 31,31,4; addi 29,29,4; cmplwi 28,8; ble 0b; addi 29,30,100; addi 25,30,104; addi 26,30,108; li 28,0; li 27,0; li 30,0; 1:; mr 3,29; mr 4,31; li 5,64; addi 28,28,1; bl _s8031ED68_8; addi 31,31,64; stwx 27,30,25; addi 29,29,64; stwx 27,30,26; cmplwi 28,1; addi 30,30,64; ble 1b; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8031ED68_0();
extern "C" void _s8031ED68_1();
extern "C" void _s8031ED68_2();
extern "C" void _s8031ED68_3();
extern "C" void _s8031ED68_4();
extern "C" void _s8031ED68_5();
extern "C" void _s8031ED68_6();
extern "C" void _s8031ED68_7();
extern "C" void _s8031ED68_8();
extern "C" void f_8031ED68() {}
