// 0x802BC858 EAStringC::ReserveSize(unsigned (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lhz 6,0x2(9); cmplw 6,4; ble 0f; mr 6,4; 0:; li 5,0; li 7,1; mr 8,6; bl _s802BC858_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802BC858_0();
extern "C" void f_802BC858() {}
