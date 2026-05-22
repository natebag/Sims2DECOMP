// 0x803B2180 void (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 30,5; mr 28,3; mr 31,6; cmplw 30,29; bge 0f; add 0,30,31; cmplw 0,29; bgt 0f; cmpwi 31,0; bne 2f; 0:; bl _s803B2180_0; cmpwi 3,0; beq 1f; li 9,0; stw 9,0x0(9); 1:; .long 0x00000001; 2:; mr 5,30; subf 0,5,29; subf. 29,31,0; beq 4f; mulli 0,31,20; mulli 9,5,20; add 0,0,28; add 30,9,28; add 31,9,0; 3:; mr 3,30; mr 4,31; bl _s803B2180_1; lbz 0,0x10(31); addic. 29,29,-1; stb 0,0x10(30); lbz 9,0x11(31); addi 31,31,20; stb 9,0x11(30); addi 30,30,20; bne 3b; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803B2180_0();
extern "C" void _s803B2180_1();
extern "C" void f_803B2180() {}
