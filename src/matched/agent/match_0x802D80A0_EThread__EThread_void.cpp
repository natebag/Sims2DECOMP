// 0x802D80A0 EThread::EThread(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-23592; stw 9,0x338(30); li 4,0; li 5,792; crxor 6,6,6; bl _s802D80A0_0; lis 9,-32702; li 0,0; addi 9,9,-6660; stw 0,0x334(30); stw 9,0x32c(30); mr 3,30; stw 0,0x318(30); stw 0,0x31c(30); stw 0,0x320(30); stw 0,0x324(30); stw 0,0x328(30); stw 0,0x330(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D80A0_0();
extern "C" void f_802D80A0() {}
