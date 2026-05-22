// 0x8012C36C __static_initialization_and_destruction_0 (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 6f; cmpwi 3,0; beq 2f; lis 11,-32696; li 10,7; addi 9,11,26300; li 30,6; addi 0,9,8; stw 10,0x4(9); stw 0,0x66bc(11); mr 31,0; li 29,-1; 0:; mr 3,31; bl _s8012C36C_0; stw 29,0x10(31); cmpwi 30,0; addi 31,31,20; addi 30,30,-1; bne 0b; lis 11,-32696; li 10,7; addi 9,11,26448; li 30,6; addi 0,9,8; stw 10,0x4(9); stw 0,0x6750(11); mr 31,0; li 29,-1; 1:; mr 3,31; bl _s8012C36C_1; stw 29,0x10(31); cmpwi 30,0; addi 31,31,20; addi 30,30,-1; bne 1b; addi 3,13,-24120; li 4,2; bl _s8012C36C_2; lis 9,-32698; lis 3,-32696; addi 9,9,9056; addi 3,3,26596; stw 9,-24120(13); bl _s8012C36C_3; b 6f; 2:; lis 3,-32696; li 4,2; addi 3,3,26596; bl _s8012C36C_4; lis 9,-32696; addi 3,9,26448; addic. 0,3,8; beq 4f; addi 31,3,148; cmpw 0,31; beq 4f; mr 30,0; 3:; addi 31,31,-20; li 4,0; mr 3,31; bl _s8012C36C_5; cmpw 30,31; bne 3b; 4:; lis 9,-32696; addi 3,9,26300; addic. 0,3,8; beq 6f; addi 31,3,148; cmpw 0,31; beq 6f; mr 30,0; 5:; addi 31,31,-20; li 4,0; mr 3,31; bl _s8012C36C_6; cmpw 30,31; bne 5b; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8012C36C_0();
extern "C" void _s8012C36C_1();
extern "C" void _s8012C36C_2();
extern "C" void _s8012C36C_3();
extern "C" void _s8012C36C_4();
extern "C" void _s8012C36C_5();
extern "C" void _s8012C36C_6();
extern "C" void f_8012C36C() {}
