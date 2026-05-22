// 0x802675D0 _Deque_base<StateMachineStatus (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-23128(13); li 4,1; stw 4,-23116(13); cmplwi 0,0; beq 0f; bl _s802675D0_0; b 1f; 0:; addi 12,3,0; mtspr 8,12; blrl; 1:; li 0,0; stw 0,-23116(13); addi 3,1,16; bl _s802675D0_1; mr 3,31; bl _s802675D0_2; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s802675D0_0();
extern "C" void _s802675D0_1();
extern "C" void _s802675D0_2();
extern "C" void f_802675D0() {}
