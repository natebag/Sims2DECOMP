// 0x802D51F4 EString2::Remove(wchar_t) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,4; bl _s802D51F4_0; cmpwi 3,-1; beq 3f; addi 30,1,8; mr 3,31; bl _s802D51F4_1; mr 28,30; mr 4,3; mr 3,30; bl _s802D51F4_2; lwz 11,0x0(31); lwz 9,0x8(1); lhz 0,0x0(11); cmpwi 0,0; beq 2f; 0:; cmpw 0,29; beq 1f; sth 0,0x0(9); addi 9,9,2; 1:; lhzu 0,0x2(11); cmpwi 0,0; bne 0b; 2:; li 0,0; mr 3,31; sth 0,0x0(9); lwz 4,0x8(1); bl _s802D51F4_3; lwz 4,0x8(1); mr 3,28; bl _s802D51F4_4; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D51F4_0();
extern "C" void _s802D51F4_1();
extern "C" void _s802D51F4_2();
extern "C" void _s802D51F4_3();
extern "C" void _s802D51F4_4();
extern "C" void f_802D51F4() {}
