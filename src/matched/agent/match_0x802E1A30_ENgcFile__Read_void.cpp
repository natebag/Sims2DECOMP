// 0x802E1A30 ENgcFile::Read(void (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,5; mr 28,3; mr 30,4; mr 31,29; cmpwi 29,0; beq 1f; 0:; mr 4,30; mr 5,31; mr 3,28; bl _s802E1A30_0; add 30,30,3; subf. 31,3,31; bne 0b; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802E1A30_0();
extern "C" void f_802E1A30() {}
