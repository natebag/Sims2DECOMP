// 0x801BE7BC ObjFnTableQuickData::LoadFromIndex(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_801BE7D8" lines="li 0,2"
extern "C" void f_801BE7D8();
extern "C" void f_801BE7BC() {}
