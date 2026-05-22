// 0x80056828 ISimInstance::Construct(ISimInstance (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80056828_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80056828_0();
extern "C" void f_80056828() {}
