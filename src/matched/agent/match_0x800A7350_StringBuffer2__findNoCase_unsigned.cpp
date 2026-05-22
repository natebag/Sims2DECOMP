// 0x800A7350 StringBuffer2::findNoCase(unsigned (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 24,4; mr 27,3; mr 30,5; mr 3,24; bl _s800A7350_0; mr 29,30; mr 28,3; mr 3,27; bl _s800A7350_1; subf 3,28,3; addi 26,3,1; cmpw 29,26; bge 7f; 0:; li 30,0; li 25,1; cmpw 30,28; bge 4f; mr 31,24; 1:; mr 3,27; add 4,29,30; bl _s800A7350_2; addi 0,3,-65; lhz 9,0x0(31); rlwinm 0,0,0,16,31; addi 31,31,2; cmplwi 0,25; bgt 2f; addi 0,3,32; rlwinm 3,0,0,16,31; 2:; addi 0,9,-65; cmplwi 0,25; bgt 3f; addi 0,9,32; rlwinm 9,0,0,16,31; 3:; cmpw 3,9; bne 5f; addi 30,30,1; cmpw 30,28; blt 1b; 4:; cmpwi 25,0; beq 6f; mr 3,29; b 8f; 5:; li 25,0; b 4b; 6:; addi 29,29,1; cmpw 29,26; blt 0b; 7:; li 3,-1; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s800A7350_0();
extern "C" void _s800A7350_1();
extern "C" void _s800A7350_2();
extern "C" void f_800A7350() {}
