// 0x802B61C0 AptPrototype::objectMemberSet(AptValue (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 4,-32703; mr 31,6; mr 3,5; addi 4,4,19312; bl _s802B61C0_0; cmpwi 3,0; li 3,0; beq 0f; mr 3,30; mr 4,31; bl _s802B61C0_1; li 3,1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B61C0_0();
extern "C" void _s802B61C0_1();
extern "C" void f_802B61C0() {}
