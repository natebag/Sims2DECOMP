// 0x800D15B0 NeighborhoodImpl::NotifyAllPersons(WantFear::Notification (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,3; mr 26,4; li 28,0; li 27,0; mr. 5,5; beq 0f; lwz 27,0x18(5); 0:; lwz 3,-21484(13); li 31,0; lwz 9,0x0(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; cmpw 28,30; bge 4f; 1:; lwz 3,-21484(13); mr 4,31; lwz 9,0x0(3); lha 0,0xf8(9); lwz 9,0xfc(9); add 3,3,0; mtspr 8,9; blrl; mr 11,3; cmpw 11,27; beq 3f; lwz 9,0x4(11); lwz 0,0x1b4(9); lha 3,0x1b0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(29); mr 4,3; lha 3,0xb8(9); lwz 0,0xbc(9); add 3,29,3; mtspr 8,0; blrl; mr. 3,3; beq 3f; mr 4,26; li 5,1; bl _s800D15B0_0; mr 0,3; mr 3,28; cmpw 3,0; bge 2f; mr 3,0; 2:; stw 3,0x8(1); mr 28,3; 3:; addi 31,31,1; cmpw 31,30; blt 1b; 4:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s800D15B0_0();
extern "C" void f_800D15B0() {}
