// 0x80030964 DrawSubModelShader(ERC (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x70(30); li 4,0; lfs f1,0x24(29); lwz 0,0x1bc(9); lha 3,0x1b8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); lwz 4,0x0(29); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80030964() {}
