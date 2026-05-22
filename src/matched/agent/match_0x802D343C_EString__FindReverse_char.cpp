// 0x802D343C EString::FindReverse(char) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); li 3,-1; lbz 0,0x0(9); cmpwi 0,0; beq 1f; mr 3,9; bl _s802D343C_0; mr. 3,3; beq 0f; lwz 0,0x0(31); subf 3,0,3; b 1f; 0:; li 3,-1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D343C_0();
extern "C" void f_802D343C() {}
