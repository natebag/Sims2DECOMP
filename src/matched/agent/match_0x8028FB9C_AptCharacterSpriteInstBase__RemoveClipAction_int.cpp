// 0x8028FB9C AptCharacterSpriteInstBase::RemoveClipAction(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); srawi 9,0,8; andc 4,9,4; rlwimi 0,4,8,0,23; stw 0,0x1c(3)"
extern "C" void f_8028FB9C() {}
