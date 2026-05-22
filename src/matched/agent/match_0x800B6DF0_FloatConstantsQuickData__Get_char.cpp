// 0x800B6DF0 FloatConstantsQuickData::Get(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 9,0xc(30); fmr f31,f1; cmpwi 9,0; beq 4f; lwz 31,0x0(9); b 2f; 0:; lwz 3,0x4(31); mr 4,29; bl _s800B6DF0_0; cmpwi 3,0; bne 1f; lfs f1,0x0(31); b 5f; 1:; addi 31,31,8; 2:; lwz 9,0xc(30); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 3f; lwz 0,-4(9); 3:; rlwinm 0,0,3,0,28; add 0,9,0; cmpw 31,0; bne 0b; 4:; fmr f1,f31; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s800B6DF0_0();
extern "C" void f_800B6DF0() {}
