// 0x8009D1E8 BString::find_str(char (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 26,3; mr 24,4; mr 29,6; mr 28,5; bl _s8009D1E8_0; cmpwi 3,0; beq 8f; cmpwi 29,0; bne 1f; b 8f; 0:; mr 3,28; b 9f; 1:; add 23,24,29; b 7f; 2:; li 30,0; add 25,24,29; addi 27,29,-1; b 4f; 3:; mr 30,31; 4:; cmplw 30,29; bge 6f; mr 3,26; addi 31,30,1; bl _s8009D1E8_1; subf 9,30,27; subf 10,31,25; add 3,3,28; lbz 0,0x0(10); lbzx 11,3,9; li 9,1; cmpw 0,11; bne 5f; li 9,0; 5:; cmpwi 9,0; beq 3b; 6:; cmpw 30,29; beq 0b; addi 9,30,1; subf 31,30,29; subf 9,9,23; add 5,28,31; lbz 4,0x0(9); mr 3,26; extsb 4,4; bl _s8009D1E8_2; cmpwi 3,-1; beq 8f; addi 0,3,1; subf 28,31,0; 7:; mr 3,26; bl _s8009D1E8_3; subf 3,28,3; cmplw 29,3; ble 2b; 8:; li 3,-1; 9:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8009D1E8_0();
extern "C" void _s8009D1E8_1();
extern "C" void _s8009D1E8_2();
extern "C" void _s8009D1E8_3();
extern "C" void f_8009D1E8() {}
