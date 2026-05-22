// 0x802D3DB4 EString::Insert(int, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 30,4; mr 27,5; bl _s802D3DB4_0; cmpw 30,3; ble 0f; mr 3,28; bl _s802D3DB4_1; mr 30,3; 0:; cmpwi 27,0; beq 1f; mr 3,27; bl _s802D3DB4_2; mr 31,3; b 2f; 1:; li 31,0; 2:; mr 3,28; bl _s802D3DB4_3; mr 29,3; cmpwi 31,0; ble 3f; add 29,29,31; mr 3,28; mr 4,29; bl _s802D3DB4_4; subf 5,30,29; add 30,3,30; subf 5,31,5; mr 4,30; addi 5,5,1; add 3,30,31; bl _s802D3DB4_5; mr 3,30; mr 4,27; mr 5,31; crxor 6,6,6; bl _s802D3DB4_6; mr 3,28; bl _s802D3DB4_7; 3:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802D3DB4_0();
extern "C" void _s802D3DB4_1();
extern "C" void _s802D3DB4_2();
extern "C" void _s802D3DB4_3();
extern "C" void _s802D3DB4_4();
extern "C" void _s802D3DB4_5();
extern "C" void _s802D3DB4_6();
extern "C" void _s802D3DB4_7();
extern "C" void f_802D3DB4() {}
