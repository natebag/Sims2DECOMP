// 0x802CBE2C ENDummy::Write(EStream (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,4; mr 28,3; lwz 9,0x18(31); addi 4,1,8; li 5,4; li 0,0; lha 3,0x38(9); li 27,0; lwz 9,0x3c(9); add 3,31,3; stw 0,0x8(1); mtspr 8,9; blrl; lwz 9,0x18(31); mr 4,28; li 5,64; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,1,12; li 5,4; lwz 0,0x40(28); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; stw 0,0xc(1); mtspr 8,9; blrl; lwz 9,0x18(31); addi 4,1,16; li 5,4; lwz 0,0x44(28); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; stw 0,0x10(1); mtspr 8,9; blrl; lwz 0,0x44(28); cmpw 27,0; bge 1f; li 29,0; 0:; lwz 9,0x18(31); addi 4,1,20; lwz 11,0x48(28); li 5,4; lha 3,0x38(9); addi 27,27,1; lwz 9,0x3c(9); add 30,11,29; add 3,31,3; lwzx 0,11,29; mtspr 8,9; addi 29,29,80; stw 0,0x14(1); blrl; addi 4,30,4; mr 3,31; bl _s802CBE2C_0; addi 4,30,16; mr 3,31; bl _s802CBE2C_1; lwz 0,0x44(28); cmpw 27,0; blt 0b; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s802CBE2C_0();
extern "C" void _s802CBE2C_1();
extern "C" void f_802CBE2C() {}
