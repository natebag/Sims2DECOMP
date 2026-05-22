// 0x80053E60 ISimsObjectModel::ShouldAnimStartImmediate(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,0; li 3,1; bnelr; li 3,0"
extern "C" int f_80053E60() {}
