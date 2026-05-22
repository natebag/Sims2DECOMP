// 0x802F1470 EGraphics::Close(ERC (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr. 31,4; beq 1f; lwz 9,0x70(31); lwz 0,0x2a4(9); lha 3,0x2a0(9); mtspr 8,0; add 3,31,3; blrl; lwz 3,0x0(31); bl _s802F1470_0; lwz 9,0x0(29); mr 4,31; lwz 30,0xc(31); lha 3,0x1e0(9); lwz 0,0x1e4(9); mr 5,30; add 3,29,3; lwz 31,0x0(31); mtspr 8,0; blrl; cmpwi 30,0; beq 0f; mr 3,31; b 2f; 0:; lwz 9,0x0(29); mr 4,31; li 5,1; lha 3,0xa0(9); lwz 0,0xa4(9); add 3,29,3; mtspr 8,0; blrl; stw 30,0x324(29); 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F1470_0();
extern "C" void f_802F1470() {}
