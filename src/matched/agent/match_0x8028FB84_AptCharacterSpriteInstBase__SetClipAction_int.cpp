// 0x8028FB84 AptCharacterSpriteInstBase::SetClipAction(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); srawi 9,0,8; or 9,9,4; rlwimi 0,9,8,0,23; stw 0,0x1c(3)"
extern "C" void f_8028FB84() {}
