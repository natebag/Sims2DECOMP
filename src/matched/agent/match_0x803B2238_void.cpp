// 0x803B2238 void (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 30,5; mr 28,3; mr 31,6; cmplw 30,29; bge 0f; add 0,30,31; cmplw 0,29; bgt 0f; cmpwi 31,0; bne 2f; 0:; bl _s803B2238_0; cmpwi 3,0; beq 1f; li 9,0; stw 9,0x0(9); 1:; .long 0x00000001; 2:; mr 5,30; subf 0,5,29; subf. 9,31,0; mtspr 9,9; beq 4f; rlwinm 0,31,2,0,29; rlwinm 9,5,2,0,29; add 0,0,28; add 3,9,28; add 5,9,0; 3:; lwz 0,0x0(5); addi 5,5,4; stw 0,0x0(3); addi 3,3,4; bdnz 3b; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803B2238_0();
extern "C" void f_803B2238() {}
