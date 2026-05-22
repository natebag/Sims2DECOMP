// 0x80060210 FlashPiMenu::GetPlayerId(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8006021C" lines="bl _s80060210_0"
extern "C" void _s80060210_0();
extern "C" void f_8006021C();
extern "C" void f_80060210() {}
