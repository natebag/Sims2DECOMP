// 0x802D3498 EString::Convert(float) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 30,0x30(1); stw 0,0x3c(1); mr 30,3; lis 4,-32702; addi 4,4,-6896; addi 3,1,8; creqv 6,6,6; bl _s802D3498_0; mr 3,30; addi 4,1,8; bl _s802D3498_1; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x30(1); addi 1,1,56"
extern "C" void _s802D3498_0();
extern "C" void _s802D3498_1();
extern "C" void f_802D3498() {}
