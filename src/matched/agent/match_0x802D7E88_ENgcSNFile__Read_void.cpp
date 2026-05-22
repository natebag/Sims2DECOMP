// 0x802D7E88 ENgcSNFile::Read(void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,5; mr 28,3; mr 30,4; mr 31,29; cmpwi 29,0; beq 2f; 0:; mr 3,28; mr 4,30; mr 5,31; bl _s802D7E88_0; mr. 3,3; bne 1f; li 3,0; b 3f; 1:; add 30,30,3; subf. 31,3,31; bne 0b; 2:; mr 3,29; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D7E88_0();
extern "C" void f_802D7E88() {}
