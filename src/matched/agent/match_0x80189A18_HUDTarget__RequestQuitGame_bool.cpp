// 0x80189A18 HUDTarget::RequestQuitGame(bool) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; li 0,1; stb 0,0x100(3); blr; 0:; stb 4,0x100(3)"
extern "C" void f_80189A18() {}
