// 0x801D0A74 PAZBase::GetLocalizable(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16416(1); mfspr 0,8; stmw 29,0x4014(1); stw 0,0x4024(1); addi 29,1,8; mr 31,3; mr 30,4; li 5,16384; li 4,0; mr 3,29; crxor 6,6,6; bl _s801D0A74_0; lwz 9,0xb0(31); mr 4,30; lwz 3,0x3c(9); bl _s801D0A74_1; cmpwi 3,0; bne 1f; lwz 0,0x8c(31); lwz 9,0xa8(31); mulli 0,0,28; add 9,9,0; lwz 5,0x4(9); cmpwi 5,0; beq 1f; lis 4,-32697; addi 3,1,16392; addi 4,4,24012; crxor 6,6,6; bl _s801D0A74_2; lwz 9,0x4008(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,29; bl _s801D0A74_3; 1:; addi 3,1,8; bl _s801D0A74_4; addi 3,1,8; bl _s801D0A74_5; addi 3,1,8; bl _s801D0A74_6; addi 3,1,8; bl _s801D0A74_7; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801D0A74_8; mr. 31,3; li 3,0; beq 2f; mr 3,31; addi 4,1,8; bl _s801D0A74_9; mr 3,31; 2:; lwz 0,0x4024(1); mtspr 8,0; lmw 29,0x4014(1); addi 1,1,16416"
extern "C" void _s801D0A74_0();
extern "C" void _s801D0A74_1();
extern "C" void _s801D0A74_2();
extern "C" void _s801D0A74_3();
extern "C" void _s801D0A74_4();
extern "C" void _s801D0A74_5();
extern "C" void _s801D0A74_6();
extern "C" void _s801D0A74_7();
extern "C" void _s801D0A74_8();
extern "C" void _s801D0A74_9();
extern "C" void f_801D0A74() {}
