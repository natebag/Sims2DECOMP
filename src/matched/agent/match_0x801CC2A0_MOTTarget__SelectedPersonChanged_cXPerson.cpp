// 0x801CC2A0 MOTTarget::SelectedPersonChanged(cXPerson (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x168(3)"
extern "C" void f_801CC2A0() {}
