// 0x801B3CC8 FCMTarget::SetVariable(char (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801B3CC8_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,2196; bl _s801B3CC8_1; mr. 3,3; bne 1f; stw 3,0x8c(30); b 5f; 1:; lis 3,-32705; mr 4,31; addi 3,3,2216; bl _s801B3CC8_2; mr. 29,3; bne 2f; stw 29,0x8c(30); lis 4,-32705; addi 4,4,2236; addi 3,30,168; li 5,0; li 6,0; bl _s801B3CC8_3; stw 29,0x88(30); b 5f; 2:; lis 3,-32705; mr 4,31; addi 3,3,2240; bl _s801B3CC8_4; mr. 3,3; bne 3f; stw 3,0x9c(30); b 5f; 3:; lis 3,-32705; mr 4,31; addi 3,3,2260; bl _s801B3CC8_5; cmpwi 3,0; bne 4f; li 0,1; stw 3,0x94(30); stw 0,0x98(30); b 5f; 4:; lis 3,-32705; mr 4,31; addi 3,3,2280; bl _s801B3CC8_6; cmpwi 3,0; bne 5f; stw 3,0x98(30); stw 3,0x94(30); 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801B3CC8_0();
extern "C" void _s801B3CC8_1();
extern "C" void _s801B3CC8_2();
extern "C" void _s801B3CC8_3();
extern "C" void _s801B3CC8_4();
extern "C" void _s801B3CC8_5();
extern "C" void _s801B3CC8_6();
extern "C" void f_801B3CC8() {}
