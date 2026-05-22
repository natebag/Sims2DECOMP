// 0x802BDB78 EAStringC::UTF8_GetBuffer(int) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 9,0x0(3); mr 30,4; li 31,0; addi 3,9,8; cmpw 31,30; bge 2f; 0:; addi 4,1,8; bl _s802BDB78_0; lwz 0,0x8(1); cmpwi 0,0; bne 1f; li 3,0; b 2f; 1:; addi 31,31,1; cmpw 31,30; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802BDB78_0();
extern "C" void f_802BDB78() {}
