// 0x802C7BB0 EFixedString::FindNoCase(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,4; mr 26,3; mr 3,25; li 30,0; bl _s802C7BB0_0; mr 28,3; mr 3,26; bl _s802C7BB0_1; subf 27,28,3; cmpw 30,27; bgt 5f; 0:; li 29,1; li 31,0; b 2f; 1:; addi 31,31,1; 2:; cmpw 31,28; bge 3f; lwz 11,0x0(26); add 9,30,31; lbzx 4,25,31; lbzx 3,11,9; extsb 4,4; extsb 3,3; bl _s802C7BB0_2; cmpwi 3,0; bne 1b; li 29,0; 3:; cmpwi 29,0; beq 4f; mr 3,30; b 6f; 4:; addi 30,30,1; cmpw 30,27; ble 0b; 5:; li 3,-1; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802C7BB0_0();
extern "C" void _s802C7BB0_1();
extern "C" void _s802C7BB0_2();
extern "C" void f_802C7BB0() {}
