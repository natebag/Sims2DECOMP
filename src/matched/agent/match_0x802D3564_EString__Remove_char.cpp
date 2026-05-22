// 0x802D3564 EString::Remove(char) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,4; li 5,0; bl _s802D3564_0; cmpwi 3,-1; beq 3f; addi 30,1,8; mr 3,31; bl _s802D3564_1; mr 28,30; mr 4,3; mr 3,30; bl _s802D3564_2; lwz 10,0x0(31); lwz 11,0x8(1); lbz 9,0x0(10); cmpwi 9,0; beq 2f; 0:; extsb 0,9; cmpw 0,29; beq 1f; stb 9,0x0(11); addi 11,11,1; 1:; lbzu 9,0x1(10); cmpwi 9,0; bne 0b; 2:; li 0,0; mr 3,31; stb 0,0x0(11); lwz 4,0x8(1); bl _s802D3564_3; lwz 4,0x8(1); mr 3,28; bl _s802D3564_4; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D3564_0();
extern "C" void _s802D3564_1();
extern "C" void _s802D3564_2();
extern "C" void _s802D3564_3();
extern "C" void _s802D3564_4();
extern "C" void f_802D3564() {}
