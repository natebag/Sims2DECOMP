// 0x80177B44 UIObjectBase::pushAptButtonFilterALL(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; bl _s80177B44_0; mr. 30,3; bne 0f; li 3,0; b 2f; 0:; li 31,1; 1:; mr 5,31; mr 3,29; mr 4,30; addi 31,31,1; bl _s80177B44_1; cmplwi 31,49; ble 1b; mr 3,30; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80177B44_0();
extern "C" void _s80177B44_1();
extern "C" void f_80177B44() {}
