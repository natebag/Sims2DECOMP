// 0x802D1440 EStorable::IsDerivedFrom(ETypeInfo (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr 4,31; bl _s802D1440_0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802D1440_0();
extern "C" void f_802D1440() {}
