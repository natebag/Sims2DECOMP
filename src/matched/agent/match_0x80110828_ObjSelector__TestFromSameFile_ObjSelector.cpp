// 0x80110828 ObjSelector::TestFromSameFile(ObjSelector (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); lwz 3,0x4(4); xor 3,0,3; subfic 9,3,0; adde 3,9,3"
extern "C" int f_80110828() {}
