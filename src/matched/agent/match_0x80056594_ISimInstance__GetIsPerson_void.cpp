// 0x80056594 ISimInstance::GetIsPerson(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x328(3); cmpwi 11,0; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; bl _s80056594_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80056594_0();
extern "C" void f_80056594() {}
