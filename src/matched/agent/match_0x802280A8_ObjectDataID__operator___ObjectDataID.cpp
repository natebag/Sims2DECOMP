// 0x802280A8 ObjectDataID::operator==(ObjectDataID (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0xc(1); bl _s802280A8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; blr; blr; blr; li 3,0"
extern "C" void _s802280A8_0();
extern "C" void f_802280A8() {}
