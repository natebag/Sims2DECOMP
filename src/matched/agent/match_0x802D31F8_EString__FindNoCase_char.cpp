// 0x802D31F8 EString::FindNoCase(char) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x0(3); mr 29,4; li 30,0; lbz 3,0x0(31); cmpwi 3,0; beq 2f; 0:; extsb 3,3; mr 4,29; bl _s802D31F8_0; cmpwi 3,0; beq 1f; mr 3,30; b 3f; 1:; lbzu 3,0x1(31); addi 30,30,1; cmpwi 3,0; bne 0b; 2:; li 3,-1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D31F8_0();
extern "C" void f_802D31F8() {}
