// 0x802B921C AptFrameStack::DestroyGCPointers(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x20(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,26124; lha 3,0x10(9); addi 5,5,25984; lwz 0,0x14(9); li 6,133; add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,31; bl _s802B921C_0; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802B921C_0();
extern "C" void f_802B921C() {}
