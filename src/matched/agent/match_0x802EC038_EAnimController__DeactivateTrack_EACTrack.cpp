// 0x802EC038 EAnimController::DeactivateTrack(EACTrack (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr. 31,4; beq 10f; lwz 11,0x8c(31); li 30,0; addi 3,31,140; cmpwi 11,0; beq 2f; li 10,-1; 0:; lwz 9,0x1c(11); lwz 0,0x30(9); stw 10,0x74(9); andis. 8,0,8; beq 1f; mr 30,9; 1:; lwz 11,0x10(11); cmpwi 11,0; bne 0b; 2:; bl _s802EC038_0; cmpwi 30,0; beq 3f; mr 4,30; mr 3,29; bl _s802EC038_1; 3:; lwz 0,0x74(31); cmpwi 0,-1; beq 4f; lis 9,-32702; mr 3,29; lfs f1,-4524(9); mr 4,31; li 5,0; bl _s802EC038_2; 4:; lwz 9,0x30(31); andis. 0,9,4; beq 6f; lwz 11,0x70(29); rlwinm 30,9,4,28,31; li 0,-1; stbx 0,11,30; lwz 9,0x38(29); addi 9,9,-3; cmpw 30,9; bgt 5f; lwz 9,0x70(29); add 9,30,9; lbz 0,0x1(9); extsb 0,0; cmpwi 0,-1; beq 5f; mulli 0,0,176; lwz 4,0x44(29); mr 3,29; add 4,4,0; bl _s802EC038_3; 5:; stw 30,0x6c(29); 6:; lwz 0,0xa8(31); cmpwi 0,0; bne 7f; stw 0,0x30(31); b 10f; 7:; mr 3,29; mr 4,31; bl _s802EC038_4; li 30,0; lwz 3,0x7c(31); stw 30,0xac(31); cmpwi 3,0; beq 8f; bl _s802EC038_5; stw 30,0x7c(31); 8:; lwz 0,0x30(31); stw 30,0x7c(31); stw 30,0xa8(31); andis. 8,0,1; beq 9f; li 0,-1; stw 0,0x8(29); 9:; stw 30,0x30(31); 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802EC038_0();
extern "C" void _s802EC038_1();
extern "C" void _s802EC038_2();
extern "C" void _s802EC038_3();
extern "C" void _s802EC038_4();
extern "C" void _s802EC038_5();
extern "C" void f_802EC038() {}
