// 0x800C5848 cXMTObjectImpl::Initialize(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x0(30); bl _s800C5848_0; lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x314(11); lha 3,0x310(11); mtspr 8,0; add 3,10,3; blrl; addi 4,30,16; addi 5,30,20; bl _s800C5848_1; lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x314(11); lha 3,0x310(11); mtspr 8,0; add 3,10,3; blrl; lha 0,0x70(3); stw 0,0x18(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800C5848_0();
extern "C" void _s800C5848_1();
extern "C" void f_800C5848() {}
