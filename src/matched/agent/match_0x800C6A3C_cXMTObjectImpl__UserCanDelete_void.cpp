// 0x800C6A3C cXMTObjectImpl::UserCanDelete(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,0x4(3); lwz 9,0x4(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; b 2f; 0:; lwz 9,0x4(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,0x0(3); bl _s800C6A3C_0; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; 2:; blrl; mr. 31,3; bne 0b; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800C6A3C_0();
extern "C" void f_800C6A3C() {}
