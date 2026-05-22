// 0x802D81B8 EThread::DeallocateStack(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x324(31); cmpwi 0,0; beq 0f; bl _s802D81B8_0; lwz 4,0x31c(31); bl _s802D81B8_1; li 0,0; stw 0,0x324(31); 0:; li 0,0; stw 0,0x328(31); stw 0,0x31c(31); stw 0,0x320(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D81B8_0();
extern "C" void _s802D81B8_1();
extern "C" void f_802D81B8() {}
