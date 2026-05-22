// 0x8037950C __AXDSPDoneCallback (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 3,13,-22160; stw 0,0x4(1); li 0,1; stwu 1,-8(1); stw 0,-22168(13); bl _s8037950C_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037950C_0();
extern "C" void f_8037950C() {}
