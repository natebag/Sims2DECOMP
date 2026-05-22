// 0x800AD1A4 Behavior::SetDefaultParam(BehaviorNodeParam (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,-1; stw 0,0x4(3); stw 0,0x0(3)"
extern "C" void f_800AD1A4() {}
