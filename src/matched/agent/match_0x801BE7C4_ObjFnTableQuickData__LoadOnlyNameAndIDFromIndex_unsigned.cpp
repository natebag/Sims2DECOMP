// 0x801BE7C4 ObjFnTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_801BE7D8" lines="li 0,4"
extern "C" void f_801BE7D8();
extern "C" void f_801BE7C4() {}
