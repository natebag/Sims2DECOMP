// 0x801A6B34 CSMTarget::SetVariable(char (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801A6B34_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-30732(13); mr 4,31; bl _s801A6B34_1; mr. 3,3; bne 1f; stw 3,0x94(30); b 4f; 1:; lwz 3,-30720(13); mr 4,31; bl _s801A6B34_2; mr. 29,3; bne 2f; addi 3,1,8; bl _s801A6B34_3; lwz 4,-30604(13); addi 3,1,8; lwz 6,0x8c(30); li 5,0; bl _s801A6B34_4; stw 29,0x94(30); addi 3,1,8; stw 29,0x88(30); li 4,2; bl _s801A6B34_5; b 4f; 2:; lwz 3,-30708(13); mr 4,31; bl _s801A6B34_6; mr. 3,3; bne 3f; stw 3,0xa0(30); b 4f; 3:; lwz 3,-30696(13); mr 4,31; bl _s801A6B34_7; mr. 31,3; bne 4f; addi 3,1,8; bl _s801A6B34_8; lwz 4,-30600(13); addi 3,1,8; lwz 6,0x8c(30); li 5,0; bl _s801A6B34_9; stw 31,0xa0(30); addi 3,1,8; stw 31,0xa4(30); li 4,2; bl _s801A6B34_10; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s801A6B34_0();
extern "C" void _s801A6B34_1();
extern "C" void _s801A6B34_2();
extern "C" void _s801A6B34_3();
extern "C" void _s801A6B34_4();
extern "C" void _s801A6B34_5();
extern "C" void _s801A6B34_6();
extern "C" void _s801A6B34_7();
extern "C" void _s801A6B34_8();
extern "C" void _s801A6B34_9();
extern "C" void _s801A6B34_10();
extern "C" void f_801A6B34() {}
