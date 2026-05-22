// 0x800EC07C GlobalConstantsClient::GetFileID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31848(13)"
extern "C" int f_800EC07C() {}
