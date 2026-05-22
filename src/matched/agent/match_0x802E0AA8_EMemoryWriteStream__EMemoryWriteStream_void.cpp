// 0x802E0AA8 EMemoryWriteStream::EMemoryWriteStream(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; lis 9,-32697; stw 29,0x0(30); addi 9,9,-23520; addi 3,30,32; stw 9,0x18(30); bl _s802E0AA8_0; stw 29,0x1c(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E0AA8_0();
extern "C" void f_802E0AA8() {}
