// 0x80092988 MUStatesAutoSaveExisting::Reset(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-24656(13); stw 0,0x20(3)"
extern "C" void f_80092988() {}
