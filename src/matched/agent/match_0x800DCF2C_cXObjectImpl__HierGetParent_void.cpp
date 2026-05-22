// 0x800DCF2C cXObjectImpl::HierGetParent(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0x4(3); li 4,26; addi 3,3,40; lwz 30,0x4(29); lha 0,0x488(30); addi 30,30,1160; add 29,29,0; bl _s800DCF2C_0; lwz 0,0x4(30); lha 4,0x0(3); mr 3,29; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800DCF2C_0();
extern "C" void f_800DCF2C() {}
