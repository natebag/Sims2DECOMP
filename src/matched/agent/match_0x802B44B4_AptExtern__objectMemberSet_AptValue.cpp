// 0x802B44B4 AptExtern::objectMemberSet(AptValue (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,5; mr 30,6; addi 3,1,8; bl _s802B44B4_0; addi 4,1,8; mr 3,30; bl _s802B44B4_1; lis 30,-32694; mr 3,29; addi 30,30,-16288; bl _s802B44B4_2; mr 29,3; addi 3,1,8; bl _s802B44B4_3; lwz 0,0x3c(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s802B44B4_4; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802B44B4_0();
extern "C" void _s802B44B4_1();
extern "C" void _s802B44B4_2();
extern "C" void _s802B44B4_3();
extern "C" void _s802B44B4_4();
extern "C" void f_802B44B4() {}
