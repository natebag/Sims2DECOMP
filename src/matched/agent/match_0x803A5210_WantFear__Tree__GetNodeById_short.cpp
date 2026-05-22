// 0x803A5210 WantFear::Tree::GetNodeById(short) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x28(3); rlwinm 4,4,5,0,26; add 3,3,4"
extern "C" int f_803A5210() {}
