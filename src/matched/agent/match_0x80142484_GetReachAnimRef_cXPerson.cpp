// 0x80142484 GetReachAnimRef(cXPerson (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x4(3); mr 29,5; mr 30,4; lha 0,0x1f8(9); lwz 9,0x1fc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,-31660(13); rlwinm 3,3,2,0,29; mr 4,30; add 3,3,0; lwz 11,0x10(3); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x0(29); li 3,0; li 4,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80142484() {}
