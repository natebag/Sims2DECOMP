// 0x802D3980 EString::TrimRight(char) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s802D3980_0; mr. 3,3; beq 2f; mr 5,3; ble 1f; lwz 11,0x0(31); add 9,5,11; lbz 0,-1(9); extsb 0,0; cmpw 30,0; bne 1f; addi 0,5,-1; add 9,0,11; 0:; addic. 5,5,-1; ble 1f; lbzu 0,-1(9); extsb 0,0; cmpw 30,0; beq 0b; 1:; cmpw 5,3; beq 2f; addi 3,1,8; mr 4,31; mr 30,3; bl _s802D3980_1; lwz 4,0x8(1); mr 3,31; bl _s802D3980_2; lwz 4,0x8(1); mr 3,30; bl _s802D3980_3; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D3980_0();
extern "C" void _s802D3980_1();
extern "C" void _s802D3980_2();
extern "C" void _s802D3980_3();
extern "C" void f_802D3980() {}
