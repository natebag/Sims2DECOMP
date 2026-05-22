// 0x801F4584 INVTarget::SetOnMsgInvPrepareObjectInfo(char (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 28,3; li 0,0; lwz 9,0x84(28); addi 11,13,-28700; stw 0,0x88(28); addi 10,28,216; rlwinm 9,9,2,0,29; li 3,0; lwzx 0,9,11; rlwinm 0,0,2,0,29; lwzx 31,10,0; cmpwi 31,0; beq 12f; mr 3,31; bl _s801F4584_0; mr 30,3; mr 3,31; bl _s801F4584_1; mr 29,3; mr 3,31; bl _s801F4584_2; mr 27,3; cmpwi 30,2; beq 1f; bgt 0f; cmpwi 30,1; beq 8f; b 10f; 0:; cmpwi 30,3; beq 8f; b 10f; 1:; mr 3,31; bl _s801F4584_3; cmpwi 3,3; beq 6f; bgt 2f; cmpwi 3,1; beq 8f; cmpwi 3,2; beq 3f; b 10f; 2:; cmpwi 3,4; beq 3f; cmpwi 3,5; beq 7f; b 10f; 3:; cmpwi 29,-1; bne 4f; addi 9,1,8; stw 29,0x4(9); mr 4,9; b 5f; 4:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 11,0x5ea8(9); addi 10,1,8; mr 4,10; lwz 9,0x0(11); lwzx 0,9,8; stw 0,0x8(1); stw 29,0x4(10); 5:; mr 5,27; mr 3,28; li 6,0; bl _s801F4584_4; b 9f; 6:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 11,0x5ea0(9); addi 10,1,16; mr 4,10; mr 5,27; lwz 9,0x0(11); mr 3,28; li 6,0; lwzx 0,9,8; stw 0,0x10(1); stw 29,0x4(10); bl _s801F4584_5; b 9f; 7:; lis 9,-32697; rlwinm 8,29,2,0,29; lwz 11,0x5ea4(9); addi 10,1,24; mr 4,10; mr 5,27; lwz 9,0x0(11); mr 3,28; li 6,0; lwzx 0,9,8; stw 0,0x18(1); stw 29,0x4(10); bl _s801F4584_6; b 9f; 8:; lwz 11,-21508(13); mr 4,29; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; stw 30,0x94(28); mr 3,31; bl _s801F4584_7; mr 7,3; mr 4,30; mr 5,27; mr 3,28; li 6,0; bl _s801F4584_8; 9:; cmpwi 3,0; bne 11f; 10:; li 3,0; b 12f; 11:; li 0,1; li 3,1; stw 0,0x88(28); 12:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s801F4584_0();
extern "C" void _s801F4584_1();
extern "C" void _s801F4584_2();
extern "C" void _s801F4584_3();
extern "C" void _s801F4584_4();
extern "C" void _s801F4584_5();
extern "C" void _s801F4584_6();
extern "C" void _s801F4584_7();
extern "C" void _s801F4584_8();
extern "C" void f_801F4584() {}
