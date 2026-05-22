// 0x802D3EB4 EString::ReleaseBuffer(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 4,0x0(3); bl _s802D3EB4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D3EB4_0();
extern "C" void f_802D3EB4() {}
