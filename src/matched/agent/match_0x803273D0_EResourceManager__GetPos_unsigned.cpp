// 0x803273D0 EResourceManager::GetPos(unsigned (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 0,0; addi 5,1,8; stw 0,0xc(1); addi 6,1,12; stw 0,0x8(1); bl _s803273D0_0; lwz 3,0x8(1); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s803273D0_0();
extern "C" void f_803273D0() {}
