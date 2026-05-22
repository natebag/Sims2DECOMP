// 0x802F0AE8 EAnimController::SetTrackActive(EACTrack (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,5; lwz 0,0xa8(29); mr 31,3; cmpw 0,30; bne 2f; cmpwi 30,0; bne 7f; lwz 9,0x30(29); andis. 0,9,4; beq 1f; lwz 11,0x70(31); rlwinm 30,9,4,28,31; li 0,-1; stbx 0,11,30; lwz 9,0x38(31); addi 9,9,-3; cmpw 30,9; bgt 0f; lwz 9,0x70(31); add 9,30,9; lbz 0,0x1(9); extsb 0,0; cmpwi 0,-1; beq 0f; mulli 0,0,176; lwz 4,0x44(31); add 4,4,0; bl _s802F0AE8_0; 0:; stw 30,0x6c(31); 1:; li 0,0; stw 0,0x30(29); b 7f; 2:; cmpwi 30,0; bne 4f; lwz 0,0x30(29); lis 9,1; rlwinm 0,0,0,14,15; cmpw 0,9; bne 3f; mr 3,31; bl _s802F0AE8_1; 3:; mr 3,31; mr 4,29; bl _s802F0AE8_2; b 6f; 4:; lwz 0,0x7c(29); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; cmpwi 9,0; beq 6f; mr 3,31; mr 4,29; bl _s802F0AE8_3; mr 3,31; mr 4,29; bl _s802F0AE8_4; 6:; stw 30,0xa8(29); 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F0AE8_0();
extern "C" void _s802F0AE8_1();
extern "C" void _s802F0AE8_2();
extern "C" void _s802F0AE8_3();
extern "C" void _s802F0AE8_4();
extern "C" void f_802F0AE8() {}
