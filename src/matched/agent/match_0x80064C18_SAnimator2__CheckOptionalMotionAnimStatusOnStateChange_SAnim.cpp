// 0x80064C18 SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(SAnimator2::eAnimState) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; addi 0,30,-12; cmplwi 0,2; bgt 0f; bl _s80064C18_0; b 1f; 0:; mr 3,31; bl _s80064C18_1; 1:; lwz 0,0x2c(31); cmpwi 0,9; beq 2f; cmpwi 0,0; bne 3f; 2:; cmpwi 30,9; beq 3f; mr 3,31; bl _s80064C18_2; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80064C18_0();
extern "C" void _s80064C18_1();
extern "C" void _s80064C18_2();
extern "C" void f_80064C18() {}
