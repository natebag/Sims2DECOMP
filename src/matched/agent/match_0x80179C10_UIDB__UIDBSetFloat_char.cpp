// 0x80179C10 UIDB::UIDBSetFloat(char (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stfd f31,0x8(1); stw 0,0x14(1); lwz 0,-31520(13); mr 9,3; fmr f31,f1; li 3,0; cmpwi 0,0; beq 1f; mr 3,9; li 4,102; bl _s80179C10_0; mr. 3,3; beq 0f; stfs f31,0x8(3); 0:; li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lfd f31,0x8(1); addi 1,1,16"
extern "C" void _s80179C10_0();
extern "C" void f_80179C10() {}
