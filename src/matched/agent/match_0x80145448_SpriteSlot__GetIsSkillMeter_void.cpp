// 0x80145448 SpriteSlot::GetIsSkillMeter(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x48(3); rlwinm 3,3,28,31,31"
extern "C" int f_80145448() {}
