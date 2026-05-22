// 0x802BE008 EAStringC::UTF8_Find(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 28,3; mr 30,5; lwz 9,0x0(28); li 31,0; mr 27,4; cmpw 31,30; addi 29,9,8; mr 3,29; bge 1f; 0:; addi 4,1,8; bl _s802BE008_0; lwz 0,0x8(1); cmpwi 0,0; beq 3f; addi 31,31,1; cmpw 31,30; blt 0b; 1:; cmpwi 3,0; bne 4f; 2:; li 3,-1; b 9f; 3:; li 3,0; b 1b; 4:; subf 31,29,3; mr 4,27; mr 3,28; mr 5,31; bl _s802BE008_1; mr. 10,3; blt 2b; mr 5,31; mr 3,30; mr 9,29; cmpw 5,10; bge 9f; 5:; lbz 0,0x0(9); mr 11,0; andi. 8,0,128; bne 6f; li 11,1; b 8f; 6:; rlwinm 0,0,0,24,26; cmpwi 0,192; bne 7f; li 11,2; b 8f; 7:; rlwinm 0,11,0,24,27; li 11,4; cmpwi 0,224; bne 8f; li 11,3; 8:; add 5,5,11; add 9,9,11; addi 3,3,1; cmpw 5,10; blt 5b; 9:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802BE008_0();
extern "C" void _s802BE008_1();
extern "C" void f_802BE008() {}
