// 0x800D9448 ObjDefinition::GetSubIndex(int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,8,0,23; rlwinm 4,4,0,24,31; or 3,3,4; extsh 3,3"
extern "C" int f_800D9448() {}
