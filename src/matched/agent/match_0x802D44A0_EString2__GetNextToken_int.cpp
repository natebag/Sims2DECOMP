// 0x802D44A0 EString2::GetNextToken(int (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8216(1); mfspr 0,8; stmw 29,0x200c(1); stw 0,0x201c(1); lwz 9,0x0(4); mr 29,3; lhz 0,0x0(9); cmpwi 0,0; beq 2f; cmpwi 7,0; mcrf cr7,cr0; beq 2f; lwz 0,0x0(5); cmpw 0,6; bge 2f; add 0,0,0; add 11,9,0; 0:; lhz 0,0x0(11); cmpw 0,7; bne 1f; beq cr7,1f; lwz 9,0x0(5); addi 9,9,1; stw 9,0x0(5); lhz 0,0x0(11); addi 11,11,2; cmpwi 0,0; bne 0b; 1:; lhz 0,0x0(11); lwz 10,0x0(5); cmpwi 0,0; bne 3f; 2:; lis 4,-32702; mr 3,29; addi 4,4,-6888; bl _s802D44A0_0; b 6f; 3:; add 8,10,10; addi 31,1,8; 4:; lhz 0,0x0(11); cmpw 0,7; beq 5f; cmpwi 0,0; beq 5f; lwz 9,0x0(5); addi 9,9,1; stw 9,0x0(5); lhz 0,0x0(11); addi 11,11,2; cmpwi 0,0; bne 4b; 5:; lwz 30,0x0(5); mr 3,31; lwz 4,0x0(4); subf 30,10,30; mr 5,30; add 4,8,4; crxor 6,6,6; bl _s802D44A0_1; lis 9,-32702; add 30,30,30; addi 9,9,-6888; mr 4,31; sthx 9,31,30; mr 3,29; bl _s802D44A0_2; 6:; mr 3,29; lwz 0,0x201c(1); mtspr 8,0; lmw 29,0x200c(1); addi 1,1,8216"
extern "C" void _s802D44A0_0();
extern "C" void _s802D44A0_1();
extern "C" void _s802D44A0_2();
extern "C" void f_802D44A0() {}
