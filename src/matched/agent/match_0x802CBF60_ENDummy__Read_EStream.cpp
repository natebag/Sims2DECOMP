// 0x802CBF60 ENDummy::Read(EStream (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,4; mr 29,3; lwz 9,0x18(31); addi 4,1,8; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x8(1); cmpwi 0,0; bne 1f; lwz 9,0x18(31); mr 4,29; li 5,64; li 27,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,29,64; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,29,68; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x44(29); addi 3,29,72; li 5,0; bl _s802CBF60_0; lwz 0,0x44(29); cmpw 27,0; bge 1f; li 28,0; 0:; lwz 9,0x18(31); li 5,4; lwz 30,0x48(29); addi 27,27,1; lwz 0,0x34(9); lha 3,0x30(9); add 30,30,28; mtspr 8,0; mr 4,30; add 3,31,3; addi 28,28,80; blrl; addi 4,30,4; mr 3,31; bl _s802CBF60_1; addi 4,30,16; mr 3,31; bl _s802CBF60_2; lwz 0,0x44(29); cmpw 27,0; blt 0b; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802CBF60_0();
extern "C" void _s802CBF60_1();
extern "C" void _s802CBF60_2();
extern "C" void f_802CBF60() {}
