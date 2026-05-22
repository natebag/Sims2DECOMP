// 0x8036C35C ENgcAram::Open(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1168(1); mfspr 0,8; stmw 30,0x488(1); stw 0,0x494(1); lwz 0,-25832(13); cmpwi 0,0; bne 1f; li 4,0; li 3,0; bl _s8036C35C_0; addi 30,1,39; bl _s8036C35C_1; li 10,64; lis 9,-32690; mtspr 9,10; addi 9,9,-6528; li 11,-1; li 0,0; addi 9,9,32; 0:; stw 11,0x4(9); stw 0,0x0(9); addi 9,9,40; bdnz 0b; li 0,1; rlwinm 30,30,0,0,26; stw 0,-25832(13); bl _s8036C35C_2; mr 9,3; li 4,0; addi 0,9,256; li 5,256; stw 0,-25824(13); mr 3,30; stw 9,-25828(13); bl _s8036C35C_3; lwz 4,-25828(13); mr 3,30; li 5,256; bl _s8036C35C_4; 1:; lwz 0,0x494(1); mtspr 8,0; lmw 30,0x488(1); addi 1,1,1168"
extern "C" void _s8036C35C_0();
extern "C" void _s8036C35C_1();
extern "C" void _s8036C35C_2();
extern "C" void _s8036C35C_3();
extern "C" void _s8036C35C_4();
extern "C" void f_8036C35C() {}
