// 0x801D5C80 PCTTarget::on_PCT_SetVisible(bool) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,0; stw 4,0xec(31); beq 0f; lwz 3,0x214(31); bl _s801D5C80_0; b 3f; 0:; lwz 3,0x214(31); bl _s801D5C80_1; lwz 0,0xe8(31); cmpwi 0,0; beq 1f; lwz 4,0xb8(31); mr 3,31; bl _s801D5C80_2; mr 4,3; mr 3,31; bl _s801D5C80_3; b 4f; 1:; lwz 9,0xb0(31); lwz 11,0xa8(31); mulli 9,9,20; add 0,11,9; cmpwi 0,0; bne 2f; li 3,0; b 4f; 2:; lwzx 4,11,9; mr 3,31; li 5,0; bl _s801D5C80_4; b 4f; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801D5C80_0();
extern "C" void _s801D5C80_1();
extern "C" void _s801D5C80_2();
extern "C" void _s801D5C80_3();
extern "C" void _s801D5C80_4();
extern "C" void f_801D5C80() {}
