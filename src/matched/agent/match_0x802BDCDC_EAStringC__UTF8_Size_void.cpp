// 0x802BDCDC EAStringC::UTF8_Size(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 9,0x0(3); li 30,0; addi 3,9,8; addi 31,1,8; b 1f; 0:; addi 30,30,1; 1:; mr 4,31; bl _s802BDCDC_0; lwz 0,0x8(1); cmpwi 0,0; bne 0b; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802BDCDC_0();
extern "C" void f_802BDCDC() {}
