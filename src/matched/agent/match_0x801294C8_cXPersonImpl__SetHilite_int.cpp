// 0x801294C8 cXPersonImpl::SetHilite(int) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; andi. 30,4,31; beq 0f; lwz 9,0x0(31); lwz 0,0x84(9); andi. 9,0,31; bne 1f; li 4,1; bl _s801294C8_0; b 1f; 0:; lwz 9,0x0(31); lwz 0,0x84(9); andi. 9,0,31; beq 1f; mr 3,31; li 4,0; bl _s801294C8_1; 1:; lwz 3,0x0(31); mr 4,30; bl _s801294C8_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801294C8_0();
extern "C" void _s801294C8_1();
extern "C" void _s801294C8_2();
extern "C" void f_801294C8() {}
