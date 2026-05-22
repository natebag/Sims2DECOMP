// 0x80053E74 ISimsObjectModel::ShouldKillAllAnimTracks(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subfic 0,4,0; adde 3,0,4"
extern "C" int f_80053E74() {}
