// 0x801EF364 INVTarget::GetOnLocMsgInvObjectDescription(unsigned (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lwz 9,0x84(3); addi 11,13,-28700; addi 3,3,216; mr 28,4; rlwinm 9,9,2,0,29; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 30,3,0; cmpwi 30,0; beq 5f; mr 3,30; bl _s801EF364_0; mr 31,3; mr 3,30; bl _s801EF364_1; li 0,0; mr 29,3; cmpwi 31,2; sth 0,0x0(28); beq 1f; bgt 0f; cmpwi 31,1; beq 3f; b 5f; 0:; cmpwi 31,3; beq 3f; b 5f; 1:; mr 3,30; bl _s801EF364_2; cmpwi 3,1; bne 5f; lwz 3,-21508(13); mr 4,29; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; bl _s801EF364_3; mr. 3,3; beq 5f; mr 4,3; addi 3,1,8; crxor 6,6,6; bl _s801EF364_4; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,28; bl _s801EF364_5; b 5f; 3:; lwz 3,-21508(13); mr 4,29; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; bl _s801EF364_6; mr. 3,3; beq 5f; mr 4,3; addi 3,1,12; crxor 6,6,6; bl _s801EF364_7; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,28; bl _s801EF364_8; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801EF364_0();
extern "C" void _s801EF364_1();
extern "C" void _s801EF364_2();
extern "C" void _s801EF364_3();
extern "C" void _s801EF364_4();
extern "C" void _s801EF364_5();
extern "C" void _s801EF364_6();
extern "C" void _s801EF364_7();
extern "C" void _s801EF364_8();
extern "C" void f_801EF364() {}
