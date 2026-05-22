// 0x800ECAE4 ObjectFolderImpl::GetSelectorByGUID(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); rlwinm 9,4,2,22,29; addi 29,3,64; lwzx 31,29,9; mr 27,9; stw 4,0x8(1); addi 26,1,8; li 28,0; b 1f; 0:; mr 28,31; lwz 31,0xa4(31); 1:; cmpwi 31,0; beq 2f; lwz 30,0x0(26); mr 3,31; bl _s800ECAE4_0; cmpw 30,3; bne 0b; cmpwi 28,0; beq 2f; lwz 0,0xa4(31); stw 0,0xa4(28); lwzx 9,29,27; stw 9,0xa4(31); stwx 31,29,27; 2:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s800ECAE4_0();
extern "C" void f_800ECAE4() {}
