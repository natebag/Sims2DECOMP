// 0x802E0EC4 EMemoryBufferWriteStream::EMemoryBufferWriteStream(void (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; li 0,0; addi 9,9,-23448; stw 9,0x18(11); stw 4,0x1c(11); stw 0,0x20(11); stw 0,0x0(11)"
extern "C" void f_802E0EC4() {}
