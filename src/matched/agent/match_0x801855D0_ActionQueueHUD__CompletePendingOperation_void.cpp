// 0x801855D0 ActionQueueHUD::CompletePendingOperation(void) (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; li 5,0; lwz 0,0x150(31); lwz 10,0x2c0(31); cmplw 5,0; bge 1f; mr 11,0; addi 9,31,168; 0:; lwz 0,0x0(9); addi 9,9,20; cmpw 0,10; beq 3f; addi 5,5,1; cmplw 5,11; blt 0b; 1:; lwz 26,0x150(31); 2:; lbz 0,0x168(31); cmpwi 0,3; bne 4f; li 0,2; stb 0,0x168(31); b 8f; 3:; mr 26,5; b 2b; 4:; cmpwi 0,2; bne 6f; lwz 4,0x150(31); cmplw 26,4; bge 7f; addi 3,31,156; mr 5,26; li 6,1; addi 30,31,80; bl _s801855D0_0; addi 29,31,116; rlwinm 0,26,2,0,29; lwz 4,0x150(31); lwzx 27,29,0; mr 3,30; lwzx 28,30,0; mr 5,26; li 6,1; bl _s801855D0_1; lwz 4,0x150(31); mr 3,29; mr 5,26; li 6,1; bl _s801855D0_2; lwz 9,0x150(31); addi 9,9,-1; stw 9,0x150(31); rlwinm 11,9,2,0,29; stwx 28,30,11; lwz 0,0x150(31); rlwinm 0,0,2,0,29; stwx 27,29,0; lbz 9,0x318(31); cmpwi 9,2; bne 7f; lbz 9,0x319(31); extsb 0,9; cmpw 0,26; ble 5f; addi 0,9,-1; stb 0,0x319(31); b 7f; 5:; blt 7f; extsb 4,26; mr 3,31; bl _s801855D0_3; b 7f; 6:; cmpwi 0,6; bne 7f; li 0,0; stw 0,0x154(31); stw 0,0x150(31); 7:; lbz 4,0x308(31); addi 3,31,344; li 5,0; li 6,1; bl _s801855D0_4; lbz 4,0x308(31); addi 3,31,704; li 5,0; li 6,1; bl _s801855D0_5; lbz 9,0x308(31); addi 9,9,-1; stb 9,0x308(31); 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801855D0_0();
extern "C" void _s801855D0_1();
extern "C" void _s801855D0_2();
extern "C" void _s801855D0_3();
extern "C" void _s801855D0_4();
extern "C" void _s801855D0_5();
extern "C" void f_801855D0() {}
