// 0x802600E8 __DVDCheckWaitingQueue (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s802600E8_0; li 0,4; lis 4,-32694; mtspr 9,0; addi 4,4,-17096; 0:; lwz 0,0x0(4); cmplw 0,4; beq 1f; bl _s802600E8_1; li 3,1; b 2f; 1:; addi 4,4,8; bdnz 0b; bl _s802600E8_2; li 3,0; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s802600E8_0();
extern "C" void _s802600E8_1();
extern "C" void _s802600E8_2();
extern "C" void f_802600E8() {}
