// 0x801B3074 FAMTarget::GetNameForFamily(Family (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,5; mr. 11,4; beq 1f; lwz 9,0x0(11); li 4,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr. 4,3; li 3,0; beq 0f; lwz 3,-21476(13); lwz 4,0x0(4); lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 0:; cmpwi 3,0; beq 1f; lwz 3,0xc(3); bl _s801B3074_0; mr 4,3; li 5,0; li 6,-1; addi 3,1,8; bl _s801B3074_1; addi 3,1,8; bl _s801B3074_2; mr 4,3; mr 3,31; bl _s801B3074_3; addi 3,1,8; li 4,2; bl _s801B3074_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s801B3074_0();
extern "C" void _s801B3074_1();
extern "C" void _s801B3074_2();
extern "C" void _s801B3074_3();
extern "C" void _s801B3074_4();
extern "C" void f_801B3074() {}
