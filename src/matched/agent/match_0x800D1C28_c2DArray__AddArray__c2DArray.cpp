// 0x800D1C28 _c2DArray::AddArray(_c2DArray (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-31952(13); stw 0,0x0(3); stw 3,-31952(13)"
extern "C" void f_800D1C28() {}
