// 0x801428B8 GetGlobalAnimRef(cXPerson (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-31660(13); mr 31,3; mr 29,4; mr 30,5; lwz 11,0x1c(9); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 31,0; stw 3,0x0(30); beq 0f; cmpwi 3,0; bne 0f; lis 4,-32706; mr 3,31; addi 4,4,-10540; mr 5,29; bl _s801428B8_0; li 3,-1; li 4,-1; b 1f; 0:; li 3,0; li 4,1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801428B8_0();
extern "C" void f_801428B8() {}
