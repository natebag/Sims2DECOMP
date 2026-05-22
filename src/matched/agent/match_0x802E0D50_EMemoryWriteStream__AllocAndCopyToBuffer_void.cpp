// 0x802E0D50 EMemoryWriteStream::AllocAndCopyToBuffer(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; bl _s802E0D50_0; lwz 4,0x1c(30); li 5,0; bl _s802E0D50_1; mr. 29,3; beq 1f; lwz 0,0x1c(30); li 31,0; cmplw 31,0; bge 1f; 0:; mr 4,31; mr 3,30; bl _s802E0D50_2; stbx 3,29,31; addi 31,31,1; lwz 0,0x1c(30); cmplw 31,0; blt 0b; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E0D50_0();
extern "C" void _s802E0D50_1();
extern "C" void _s802E0D50_2();
extern "C" void f_802E0D50() {}
