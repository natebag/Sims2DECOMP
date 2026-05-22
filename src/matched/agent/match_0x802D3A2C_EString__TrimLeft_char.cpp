// 0x802D3A2C EString::TrimLeft(char) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 9,4; mr 31,3; lwz 4,0x0(31); lbz 0,0x0(4); extsb 0,0; cmpw 0,9; bne 2f; lbz 0,0x1(4); mr 11,4; addi 4,4,1; b 1f; 0:; lbzu 0,0x1(4); 1:; extsb 0,0; cmpw 0,9; beq 0b; cmpw 4,11; beq 2f; mr 3,31; bl _s802D3A2C_0; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D3A2C_0();
extern "C" void f_802D3A2C() {}
