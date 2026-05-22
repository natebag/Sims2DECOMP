// 0x801E91A8 GetVar_LockedStatus::GetVar_LockedStatus(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lis 9,-32698; stw 30,0x0(31); addi 9,9,32728; mr 29,5; stw 9,0x8(31); mr 3,30; bl _s801E91A8_0; lis 9,-32698; stw 3,0x4(31); addi 9,9,32440; mr 3,30; stw 9,0x8(31); bl _s801E91A8_1; add 30,30,3; li 11,1; lbz 9,-2(30); li 10,1; lbz 0,-1(30); extsb 9,9; mulli 9,9,10; extsb 0,0; addi 9,9,-528; add 9,9,0; slw 11,11,9; and. 0,11,29; bne 0f; li 10,0; 0:; stw 10,0xc(31); mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801E91A8_0();
extern "C" void _s801E91A8_1();
extern "C" void f_801E91A8() {}
