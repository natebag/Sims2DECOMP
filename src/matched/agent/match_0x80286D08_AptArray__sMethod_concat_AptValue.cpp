// 0x80286D08 AptArray::sMethod_concat(AptValue (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 29,3; mr 26,4; lwz 9,0x0(29); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 9f; lwz 3,-23016(13); li 4,48; li 30,0; bl _s80286D08_0; bl _s80286D08_1; lwz 0,0x2c(29); mr 28,3; cmpw 30,0; bge 2f; li 31,0; 1:; lwz 9,0x24(29); mr 3,28; lwz 4,0x2c(28); addi 30,30,1; lwzx 5,31,9; addi 31,31,4; bl _s80286D08_2; lwz 0,0x2c(29); cmpw 30,0; blt 1b; 2:; li 30,0; cmpw 30,26; bge 8f; lis 25,-32694; addi 24,25,-16032; 3:; lwz 9,-16032(25); li 11,0; lwz 0,0x8(24); subf 9,30,9; rlwinm 9,9,2,0,29; add 9,9,0; lwz 31,-4(9); lwz 9,0x0(31); rlwinm 0,9,0,25,31; cmpwi 0,22; bne 4f; rlwinm 11,9,5,31,31; 4:; cmpwi 11,0; beq 6f; lwz 0,0x2c(31); li 29,0; addi 27,30,1; cmpw 29,0; bge 7f; li 30,0; 5:; lwz 9,0x24(31); mr 3,28; lwz 4,0x2c(28); addi 29,29,1; lwzx 5,30,9; addi 30,30,4; bl _s80286D08_3; lwz 0,0x2c(31); cmpw 29,0; blt 5b; b 7f; 6:; lwz 4,0x2c(28); mr 5,31; mr 3,28; bl _s80286D08_4; addi 27,30,1; 7:; mr 30,27; cmpw 30,26; blt 3b; 8:; mr 3,28; b 10f; 9:; lwz 3,-22936(13); 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80286D08_0();
extern "C" void _s80286D08_1();
extern "C" void _s80286D08_2();
extern "C" void _s80286D08_3();
extern "C" void _s80286D08_4();
extern "C" void f_80286D08() {}
