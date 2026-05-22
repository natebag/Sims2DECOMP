// 0x80364190 EFontData::Write(EStream (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,3; mr 3,4; addi 4,29,4; bl _s80364190_0; mr 30,3; addi 4,1,8; lwz 9,0x18(30); li 5,4; lwz 0,0x10(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x8(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,12; li 5,4; lwz 0,0x14(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0xc(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,16; li 5,4; lwz 0,0x20(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x10(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,20; li 5,4; lwz 0,0x18(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x14(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,24; li 5,4; lwz 0,0x1c(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x18(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,28; li 5,4; lwz 0,0x24(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x1c(1); mtspr 8,9; blrl; mr 3,30; addi 4,29,40; bl _s80364190_1; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80364190_0();
extern "C" void _s80364190_1();
extern "C" void f_80364190() {}
