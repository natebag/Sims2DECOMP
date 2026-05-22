// 0x8013532C RelArray::DoStream(ReconBuffer (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr. 29,5; ble 0f; mr 3,30; addi 4,31,16; li 5,1; bl _s8013532C_0; 0:; mr 3,31; mr 5,30; lwz 4,0x0(3); mr 6,29; bl _s8013532C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8013532C_0();
extern "C" void _s8013532C_1();
extern "C" void f_8013532C() {}
