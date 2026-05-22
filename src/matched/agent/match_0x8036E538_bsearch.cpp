// 0x8036E538 bsearch (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 24,3; mr 25,4; mr 27,6; mr 26,7; li 28,0; mr. 29,5; beq 4f; cmpwi 27,0; bne 3f; b 4f; 0:; mr 3,30; b 5f; 1:; add 9,28,29; mr 3,24; rlwinm 31,9,31,1,31; mtspr 8,26; mullw 0,31,27; add 30,25,0; mr 4,30; blrl; cmpwi 3,0; bge 2f; mr 29,31; b 3f; 2:; ble 0b; addi 28,31,1; 3:; cmplw 28,29; blt 1b; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void f_8036E538() {}
