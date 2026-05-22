// 0x802F74C0 ERC::Terminate(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,0; lwz 9,0x70(31); li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,8; li 10,1; stb 0,0x0(3); stw 10,0x10(31); lwz 11,0x0(31); stw 10,0x4c(11); lwz 9,0x44(31); lwz 11,0x0(31); addi 9,9,1; stw 9,0x60(11); lwz 0,0xc(31); cmpwi 0,1; bne 0f; mr 3,31; bl _s802F74C0_0; 0:; lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802F74C0_0();
extern "C" void f_802F74C0() {}
