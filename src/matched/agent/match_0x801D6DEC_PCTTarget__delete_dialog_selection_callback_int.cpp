// 0x801D6DEC PCTTarget::delete_dialog_selection_callback(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,0; stw 0,0xf0(31); cmpwi 4,0; bne 2f; bl _s801D6DEC_0; lwz 4,0x84(31); li 5,2; bl _s801D6DEC_1; mr. 3,3; beq 0f; bl _s801D6DEC_2; 0:; lwz 3,0x214(31); cmpwi 3,0; beq 1f; li 4,0; bl _s801D6DEC_3; lwz 3,0x214(31); li 4,0; bl _s801D6DEC_4; 1:; li 3,1; bl _s801D6DEC_5; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801D6DEC_0();
extern "C" void _s801D6DEC_1();
extern "C" void _s801D6DEC_2();
extern "C" void _s801D6DEC_3();
extern "C" void _s801D6DEC_4();
extern "C" void _s801D6DEC_5();
extern "C" void f_801D6DEC() {}
