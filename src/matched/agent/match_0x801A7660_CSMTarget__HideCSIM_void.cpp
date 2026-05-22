// 0x801A7660 CSMTarget::HideCSIM(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x98(3); cmplwi 0,0; bnelr; stw 0,0x90(3)"
extern "C" void f_801A7660() {}
