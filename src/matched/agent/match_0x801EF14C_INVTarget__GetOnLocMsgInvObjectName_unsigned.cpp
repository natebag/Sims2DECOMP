// 0x801EF14C INVTarget::GetOnLocMsgInvObjectName(unsigned (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lwz 9,0x84(3); addi 11,13,-28700; addi 3,3,216; mr 28,4; rlwinm 9,9,2,0,29; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 30,3,0; cmpwi 30,0; beq 13f; mr 3,30; bl _s801EF14C_0; mr 31,3; mr 3,30; bl _s801EF14C_1; li 0,0; mr 29,3; cmpwi 31,2; sth 0,0x0(28); beq 1f; bgt 0f; cmpwi 31,1; beq 11f; b 13f; 0:; cmpwi 31,3; beq 11f; b 13f; 1:; mr 3,30; bl _s801EF14C_2; cmpwi 3,3; beq 6f; bgt 2f; cmpwi 3,1; beq 8f; cmpwi 3,2; beq 3f; b 13f; 2:; cmpwi 3,4; beq 3f; cmpwi 3,5; beq 7f; b 13f; 3:; cmpwi 29,-1; bne 4f; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-26072; addi 3,1,8; crxor 6,6,6; bl _s801EF14C_3; lwz 9,0x8(1); b 9f; 4:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 10,0x5ea8(9); li 4,0; lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x8(11); 5:; cmpwi 3,0; beq 10f; lwz 4,0x0(3); b 10f; 6:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 10,0x5ea0(9); li 4,0; lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x4(11); b 5b; 7:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 10,0x5ea4(9); li 4,0; lwz 9,0x0(10); lwzx 11,9,8; lwz 3,0x4(11); b 5b; 8:; lwz 3,-21508(13); mr 4,29; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; bl _s801EF14C_4; mr. 3,3; beq 13f; mr 4,3; addi 3,1,12; crxor 6,6,6; bl _s801EF14C_5; lwz 9,0xc(1); 9:; li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,28; bl _s801EF14C_6; b 13f; 11:; lwz 3,-21508(13); mr 4,29; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; bl _s801EF14C_7; mr. 3,3; beq 13f; mr 4,3; addi 3,1,16; crxor 6,6,6; bl _s801EF14C_8; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 12f; lwz 4,0x0(9); 12:; mr 3,28; bl _s801EF14C_9; 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801EF14C_0();
extern "C" void _s801EF14C_1();
extern "C" void _s801EF14C_2();
extern "C" void _s801EF14C_3();
extern "C" void _s801EF14C_4();
extern "C" void _s801EF14C_5();
extern "C" void _s801EF14C_6();
extern "C" void _s801EF14C_7();
extern "C" void _s801EF14C_8();
extern "C" void _s801EF14C_9();
extern "C" void f_801EF14C() {}
