// 0x802E37F8 EEngine::GetTextureRingMemoryUseInfo(HeapUseInfo (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 0,0; addi 9,9,-5344; stw 0,0x10(4); stw 9,0x0(4); stw 0,0x4(4); stw 0,0x8(4); stw 0,0xc(4)"
extern "C" void f_802E37F8() {}
