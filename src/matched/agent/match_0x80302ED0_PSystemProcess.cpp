// 0x80302ED0 PSystemProcess (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr. 3,3; fmr f31,f1; mr 30,3; bne 0f; lwz 30,-22708(13); 0:; cmpwi 30,0; beq 11f; lwz 9,0x0(30); lwz 0,0x88(9); stw 0,0x90(9); cmpwi 4,0; mfcr 31; b 2f; 1:; lwz 9,0x0(9); stw 9,0x90(11); lwz 0,0x50(3); xori 0,0,1; andi. 9,0,1; beq 2f; fmr f1,f31; bl _s80302ED0_0; 2:; lwz 11,0x0(30); li 3,0; lwz 9,0x90(11); cmpwi 9,0; beq 3f; lwz 3,0x8(9); 3:; cmpwi 3,0; bne 1b; mtcrf 128,31; beq 7f; lwz 0,0x88(11); stw 0,0x90(11); b 5f; 4:; lwz 0,0x0(9); fmr f1,f31; stw 0,0x90(11); bl _s80302ED0_1; 5:; lwz 11,0x0(30); li 3,0; lwz 9,0x90(11); cmpwi 9,0; beq 6f; lwz 3,0x8(9); 6:; cmpwi 3,0; bne 4b; b 11f; 7:; lwz 0,0x88(11); lis 31,1024; ori 31,31,16384; stw 0,0x90(11); b 9f; 8:; lwz 0,0x0(9); stw 0,0x90(11); lwz 9,0x50(3); and. 0,9,31; beq 9f; fmr f1,f31; bl _s80302ED0_2; 9:; lwz 11,0x0(30); li 3,0; lwz 9,0x90(11); cmpwi 9,0; beq 10f; lwz 3,0x8(9); 10:; cmpwi 3,0; bne 8b; 11:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80302ED0_0();
extern "C" void _s80302ED0_1();
extern "C" void _s80302ED0_2();
extern "C" void f_80302ED0() {}
