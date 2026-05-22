// 0x80321FC8 HDDThread::GetArcIndex(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; addi 31,3,832; li 30,0; 0:; mr 3,31; mr 4,29; bl _s80321FC8_0; cmpwi 3,0; beq 1f; mr 3,30; b 2f; 1:; addi 30,30,1; addi 31,31,20; cmpwi 30,31; ble 0b; li 3,-1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80321FC8_0();
extern "C" void f_80321FC8() {}
