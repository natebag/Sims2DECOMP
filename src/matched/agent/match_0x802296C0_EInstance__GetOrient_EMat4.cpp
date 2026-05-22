// 0x802296C0 EInstance::GetOrient(EMat4 (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 3,4; bl _s802296C0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802296C0_0();
extern "C" void f_802296C0() {}
