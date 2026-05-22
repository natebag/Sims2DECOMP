// 0x802D3AE0 EString::TrimRight(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,4; bl _s802D3AE0_0; mr. 29,3; beq 3f; mr 30,29; b 1f; 0:; addi 30,30,-1; 1:; cmpwi 30,0; ble 2f; lwz 9,0x0(31); mr 3,28; add 9,30,9; lbz 4,-1(9); extsb 4,4; bl _s802D3AE0_1; cmpwi 3,0; bne 0b; 2:; cmpw 30,29; beq 3f; addi 3,1,8; mr 5,30; mr 30,3; mr 4,31; bl _s802D3AE0_2; lwz 4,0x8(1); mr 3,31; bl _s802D3AE0_3; lwz 4,0x8(1); mr 3,30; bl _s802D3AE0_4; 3:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D3AE0_0();
extern "C" void _s802D3AE0_1();
extern "C" void _s802D3AE0_2();
extern "C" void _s802D3AE0_3();
extern "C" void _s802D3AE0_4();
extern "C" void f_802D3AE0() {}
