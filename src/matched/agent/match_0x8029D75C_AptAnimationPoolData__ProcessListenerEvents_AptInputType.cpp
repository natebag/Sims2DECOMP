// 0x8029D75C AptAnimationPoolData::ProcessListenerEvents(AptInputType, (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 31,3; mr 28,6; li 30,0; cmplwi 5,1; bgt 5f; addi 9,31,24; li 27,0; lhz 0,0x2(9); mr 26,9; cmpw 30,0; bge 5f; lhz 0,0x18(31); cmpw 30,0; beq 5f; cmpwi 3,5,1; li 29,0; cmpwi 4,5,0; 0:; lwz 9,0x1c(31); lwzx 4,29,9; cmpwi 4,0; beq 4f; beq cr4,1f; beq cr3,2f; b 3f; 1:; mr 3,31; li 5,64; mr 6,28; bl _s8029D75C_0; b 3f; 2:; mr 3,31; li 5,128; mr 6,28; bl _s8029D75C_1; 3:; addi 30,30,1; 4:; lhz 0,0x2(26); addi 27,27,1; addi 29,29,4; cmpw 27,0; bge 5f; lhz 0,0x18(31); cmpw 30,0; bne 0b; 5:; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 24,12; addi 1,1,40"
extern "C" void _s8029D75C_0();
extern "C" void _s8029D75C_1();
extern "C" void f_8029D75C() {}
