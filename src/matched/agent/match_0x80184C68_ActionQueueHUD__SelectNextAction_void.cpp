// 0x80184C68 ActionQueueHUD::SelectNextAction(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lbz 9,0x319(3); lwz 8,0x150(3); addi 9,9,1; mr 10,8; extsb 4,9; b 1f; 0:; addi 0,4,1; extsb 4,0; 1:; cmpw 4,10; bge 3f; mulli 9,4,20; li 11,1; add 9,9,3; lbz 0,0xad(9); cmpwi 0,0; bne 2f; li 11,0; 2:; cmpwi 11,0; bne 0b; cmpw 4,8; bge 3f; bl _s80184C68_0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80184C68_0();
extern "C" void f_80184C68() {}
