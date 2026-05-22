// 0x802D78D4 ESemaphore::Acquire(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,-1; beq 0f; addi 3,31,12; bl _s802D78D4_0; lwz 0,0xc(31); cmpw 3,0; li 3,0; beq 2f; b 1f; 0:; addi 3,31,12; bl _s802D78D4_1; 1:; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D78D4_0();
extern "C" void _s802D78D4_1();
extern "C" void f_802D78D4() {}
