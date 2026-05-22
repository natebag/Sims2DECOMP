// 0x800BE504 IFFResFile2::Close(void) (712 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); mr 31,3; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BE504_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BE504_1; 1:; mr 3,31; bl _s800BE504_2; cmpwi 3,0; beq 2f; mr 3,31; bl _s800BE504_3; b 7f; 2:; lwz 9,0xc(31); li 30,0; lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 0,0x144(31); cmpwi 0,0; beq 3f; lwz 9,0xc(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x4(31); 3:; cmpwi 30,0; bne 4f; lwz 9,0xc(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 0,0x140(31); cmpwi 0,0; bne 4f; lwz 0,0x144(31); cmpwi 0,0; beq 4f; lwz 0,0x148(31); cmpwi 0,0; bne 4f; lwz 9,0x138(31); lwz 0,0x10(9); cmpwi 0,10239; ble 4f; mr 3,31; bl _s800BE504_4; mr 30,3; 4:; lwz 9,0xc(31); addi 27,31,16; lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; cmpwi 30,0; bne 5f; lwz 0,0x144(31); cmpwi 0,0; beq 5f; lwz 3,0x138(31); lis 4,29299; ori 4,4,28016; bl _s800BE504_5; lwz 3,0x138(31); lis 4,29299; ori 4,4,28016; li 5,0; li 6,0; bl _s800BE504_6; cmpwi 3,0; bne 5f; lwz 3,0x138(31); lis 4,29299; ori 4,4,28016; li 5,0; bl _s800BE504_7; mr. 28,3; beq 5f; addi 29,1,8; lis 30,-32706; addi 30,30,-24944; addi 4,29,8; li 5,64; mr 3,29; bl _s800BE504_8; mr 3,29; mr 4,30; li 5,-1; bl _s800BE504_9; lwz 9,0xc(31); lis 5,29299; mr 7,29; mr 4,28; lwz 0,0xfc(9); ori 5,5,28016; lha 3,0xf8(9); li 6,0; mtspr 8,0; li 8,1; add 3,31,3; blrl; lwz 0,0x4(31); cmpwi 0,0; bne 5f; lwz 9,0xc(31); mr 4,28; lwz 0,0x10c(9); lha 3,0x108(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x4(31); cmpwi 0,0; bne 5f; lwz 3,0x138(31); lis 4,29299; ori 4,4,28016; li 5,0; li 6,0; bl _s800BE504_10; mr. 3,3; beq 5f; lwz 5,0x0(3); cmpwi 5,-1; beq 5f; mr 3,31; mr 4,27; bl _s800BE504_11; 5:; lwz 3,0x138(31); bl _s800BE504_12; lwz 3,0x138(31); bl _s800BE504_13; lwz 3,0x138(31); cmpwi 3,0; beq 6f; li 4,3; bl _s800BE504_14; 6:; li 0,0; mr 3,27; stw 0,0x138(31); bl _s800BE504_15; mr 30,3; mr 3,31; mr 4,30; bl _s800BE504_16; mr 3,30; 7:; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"
extern "C" void _s800BE504_0();
extern "C" void _s800BE504_1();
extern "C" void _s800BE504_2();
extern "C" void _s800BE504_3();
extern "C" void _s800BE504_4();
extern "C" void _s800BE504_5();
extern "C" void _s800BE504_6();
extern "C" void _s800BE504_7();
extern "C" void _s800BE504_8();
extern "C" void _s800BE504_9();
extern "C" void _s800BE504_10();
extern "C" void _s800BE504_11();
extern "C" void _s800BE504_12();
extern "C" void _s800BE504_13();
extern "C" void _s800BE504_14();
extern "C" void _s800BE504_15();
extern "C" void _s800BE504_16();
extern "C" void f_800BE504() {}
