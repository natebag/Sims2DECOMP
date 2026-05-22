// 0x802F13F8 EGraphics::Open(RCMode) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; lwz 9,0x0(29); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; lwz 9,0x70(31); mr 4,30; lha 3,0x298(9); lwz 0,0x29c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 30,0; bne 0f; stw 31,0x324(29); 0:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F13F8() {}
