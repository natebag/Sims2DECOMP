// 0x80090D8C LoadingScreenStateMachine::LoadFinishing(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-32160(13); cmplwi 9,0; beqlr; li 0,1; stw 0,0xa4(9)"
extern "C" void f_80090D8C() {}
