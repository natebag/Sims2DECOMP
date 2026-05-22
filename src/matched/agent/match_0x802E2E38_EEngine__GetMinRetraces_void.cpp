// 0x802E2E38 EEngine::GetMinRetraces(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); cmplwi 0,0; li 3,1; beqlr; lwz 3,-26804(13)"
extern "C" int f_802E2E38() {}
