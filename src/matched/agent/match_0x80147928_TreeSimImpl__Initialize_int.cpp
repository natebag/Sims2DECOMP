// 0x80147928 TreeSimImpl::Initialize(int, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,5; addi 3,30,12; bl _s80147928_0; stw 29,0x30(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80147928_0();
extern "C" void f_80147928() {}
