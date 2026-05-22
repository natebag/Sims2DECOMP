// 0x8028FBB4 AptCharacterSpriteInstBase::HasClipAction(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1c(3); srawi 3,3,8; and 3,3,4"
extern "C" int f_8028FBB4() {}
