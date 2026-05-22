// 0x802D3B84 EString::TrimLeft(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 4,0x0(30); lbz 0,0x0(4); cmpwi 0,0; beq 3f; mr 31,4; b 1f; 0:; addi 31,31,1; 1:; lbz 0,0x0(31); extsb 4,0; cmpwi 4,0; beq 2f; mr 3,29; bl _s802D3B84_0; cmpwi 3,0; bne 0b; 2:; lwz 0,0x0(30); cmpw 31,0; beq 3f; mr 4,31; mr 3,30; bl _s802D3B84_1; 3:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D3B84_0();
extern "C" void _s802D3B84_1();
extern "C" void f_802D3B84() {}
