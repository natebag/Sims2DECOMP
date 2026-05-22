// 0x80092EE4 MUStatesTransitionSaveExistingGame::Draw(ERC (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x1c(31); addi 9,9,-8; cmplwi 9,1; bgt 0f; lwz 11,0x8(31); li 0,0; lwz 9,0x98(11); stw 0,0xc8(9); lwz 11,0x8(31); lwz 10,0x98(11); lwz 9,0x80(10); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x8(31); li 0,1; lwz 9,0x98(11); stw 0,0xc8(9); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80092EE4() {}
