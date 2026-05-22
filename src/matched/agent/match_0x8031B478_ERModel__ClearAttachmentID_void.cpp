// 0x8031B478 ERModel::ClearAttachmentID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,-1; stb 0,0x135(3)"
extern "C" void f_8031B478() {}
