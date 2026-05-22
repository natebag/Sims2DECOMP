// 0x802E3868 EEngine::GetMemoryUseDmaInfo(HeapUseInfo (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 0,0; addi 9,9,-5304; li 11,1; stw 0,0x10(4); stw 9,0x0(4); stw 11,0x4(4); stw 0,0x8(4); stw 0,0xc(4)"
extern "C" void f_802E3868() {}
