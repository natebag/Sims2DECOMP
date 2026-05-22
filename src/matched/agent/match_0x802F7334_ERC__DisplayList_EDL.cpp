// 0x802F7334 ERC::DisplayList(EDL (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 2f; lwz 9,0x60(30); lwz 0,0x3c(31); cmpw 9,0; bgt 2f; lwz 9,0x70(31); li 4,0; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,1; lwz 9,0x54(30); lwz 0,0x54(11); add 0,0,9; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,6; stw 30,0x4(3); stb 0,0x0(3); lwz 0,0x30(30); cmpwi 0,0; bne 0f; lwz 0,0x3c(30); cmpwi 0,0; beq 1f; 0:; mr 4,30; mr 3,31; bl _s802F7334_0; 1:; lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F7334_0();
extern "C" void f_802F7334() {}
