// 0x802D8114 EThread::EThread(int, (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-23592; li 0,0; stw 9,0x338(30); stw 0,0x318(30); bl _s802D8114_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D8114_0();
extern "C" void f_802D8114() {}
