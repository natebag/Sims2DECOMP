// 0x8015BEDC ObjectDataObjDefinition::Detach(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stb 0,0x1a(3)"
extern "C" void f_8015BEDC() {}
