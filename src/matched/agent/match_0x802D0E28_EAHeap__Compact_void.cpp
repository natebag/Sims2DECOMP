// 0x802D0E28 EAHeap::Compact(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x4fc(31); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802D0E28_0; 0:; lwz 0,0x4(31); andi. 9,0,1; beq 1f; mr 3,31; bl _s802D0E28_1; 1:; lwz 3,0x8(1); cmpwi 3,0; beq 2f; bl _s802D0E28_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s802D0E28_0();
extern "C" void _s802D0E28_1();
extern "C" void _s802D0E28_2();
extern "C" void f_802D0E28() {}
