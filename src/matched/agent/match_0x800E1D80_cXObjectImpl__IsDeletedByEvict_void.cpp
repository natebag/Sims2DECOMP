// 0x800E1D80 cXObjectImpl::IsDeletedByEvict(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,2; li 3,1; beq 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x3f8(9); lwz 9,0x3fc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; li 3,0; b 1f; 0:; addi 31,31,40; li 4,43; mr 3,31; bl _s800E1D80_0; lhz 0,0x0(3); andi. 9,0,8; mr 3,31; li 4,43; bl _s800E1D80_1; lhz 0,0x0(3); andi. 9,0,16; mfcr 3; rlwinm 3,3,3,31,31; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800E1D80_0();
extern "C" void _s800E1D80_1();
extern "C" void f_800E1D80() {}
