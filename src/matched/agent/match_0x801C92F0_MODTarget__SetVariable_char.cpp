// 0x801C92F0 MODTarget::SetVariable(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801C92F0_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-30148(13); mr 4,31; bl _s801C92F0_1; mr. 3,3; bne 1f; li 0,1; stw 3,0xf4(30); stw 0,0xfc(30); b 4f; 1:; lwz 3,-30136(13); mr 4,31; bl _s801C92F0_2; mr. 29,3; bne 2f; addi 3,1,8; bl _s801C92F0_3; lis 4,-32705; lwz 6,0x94(30); addi 4,4,12520; addi 3,1,8; li 5,0; bl _s801C92F0_4; stw 29,0xfc(30); addi 3,1,8; stw 29,0xf4(30); li 4,2; bl _s801C92F0_5; b 4f; 2:; lwz 3,-30124(13); mr 4,31; bl _s801C92F0_6; mr. 3,3; bne 3f; stw 3,0x8c(30); b 4f; 3:; lwz 3,-30112(13); mr 4,31; bl _s801C92F0_7; mr. 31,3; bne 4f; stw 31,0x8c(30); lis 4,-32705; lwz 6,0x94(30); addi 4,4,12548; addi 3,30,200; li 5,0; bl _s801C92F0_8; stw 31,0x88(30); 4:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s801C92F0_0();
extern "C" void _s801C92F0_1();
extern "C" void _s801C92F0_2();
extern "C" void _s801C92F0_3();
extern "C" void _s801C92F0_4();
extern "C" void _s801C92F0_5();
extern "C" void _s801C92F0_6();
extern "C" void _s801C92F0_7();
extern "C" void _s801C92F0_8();
extern "C" void f_801C92F0() {}
