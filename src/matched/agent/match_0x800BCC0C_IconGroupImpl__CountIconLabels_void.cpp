// 0x800BCC0C IconGroupImpl::CountIconLabels(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800BCC0C_0; lwz 11,0x8(30); cmpwi 11,0; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(11); li 4,-1; lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BCC0C_0();
extern "C" void f_800BCC0C() {}
