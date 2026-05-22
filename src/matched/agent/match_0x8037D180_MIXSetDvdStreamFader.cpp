// 0x8037D180 MIXSetDvdStreamFader (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,-49; bge 0f; li 3,-49; 0:; cmpwi 3,0; ble 1f; li 3,0; 1:; stw 3,-22068(13)"
extern "C" void f_8037D180() {}
