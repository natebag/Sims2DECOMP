// 0x8015A708 NamespaceSelector::GetSoundInfo(short) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 4,4,8; bl _s8015A708_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8015A708_0();
extern "C" void f_8015A708() {}
