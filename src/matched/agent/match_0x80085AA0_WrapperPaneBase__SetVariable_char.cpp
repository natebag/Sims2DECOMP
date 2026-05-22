// 0x80085AA0 WrapperPaneBase::SetVariable(char (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,5; addi 5,1,8; bl _s80085AA0_0; mr. 30,3; li 3,0; blt 5f; mr 3,29; bl _s80085AA0_1; lbz 0,0x8(1); extsb 0,0; cmpwi 0,120; bne 1f; rlwinm 28,30,2,0,29; addi 29,31,64; lwzx 11,29,28; lwz 0,0x4(11); andis. 9,0,4096; bne 0f; lwz 9,0x1c(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; mr 4,30; bl _s80085AA0_2; 0:; lwzx 9,29,28; lwz 0,0x4(9); oris 0,0,256; b 3f; 1:; cmpwi 0,121; bne 4f; rlwinm 28,30,2,0,29; addi 29,31,64; lwzx 11,29,28; lwz 0,0x4(11); andis. 9,0,8192; bne 2f; lwz 9,0x1c(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; mr 4,30; bl _s80085AA0_3; 2:; lwzx 9,29,28; lwz 0,0x4(9); oris 0,0,512; 3:; stw 0,0x4(9); 4:; li 3,1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80085AA0_0();
extern "C" void _s80085AA0_1();
extern "C" void _s80085AA0_2();
extern "C" void _s80085AA0_3();
extern "C" void f_80085AA0() {}
