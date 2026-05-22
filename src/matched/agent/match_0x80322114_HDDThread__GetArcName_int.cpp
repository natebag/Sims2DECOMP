// 0x80322114 HDDThread::GetArcName(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; cmplwi 4,31; ble 0f; lis 3,-32702; addi 3,3,2884; b 1f; 0:; mulli 3,4,20; addi 3,3,832; add 3,0,3; bl _s80322114_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80322114_0();
extern "C" void f_80322114() {}
