// 0x802B4358 AptValueWithHash::AptValueWithHash(AptVirtualFunctionTable_Indices, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; bl _s802B4358_0; lis 9,-32703; mr 4,29; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B4358_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802B4358_0();
extern "C" void _s802B4358_1();
extern "C" void f_802B4358() {}
