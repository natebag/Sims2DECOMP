// 0x801B2C14 FAMTarget::GetMoneyForFamilyInLotSelect(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 29,0x214(1); stw 0,0x224(1); lwz 4,0x14c(3); mr 29,5; bl _s801B2C14_0; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x128(9); lwz 0,0x12c(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; bne 0f; li 3,0; b 2f; 0:; lwz 9,0x0(11); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; cmpwi 29,0; beq 1f; addi 30,1,8; li 5,256; addi 4,30,8; mr 3,30; bl _s801B2C14_1; mr 4,30; mr 3,31; li 5,1; bl _s801B2C14_2; mr 3,30; bl _s801B2C14_3; mr 4,3; mr 3,29; bl _s801B2C14_4; 1:; mr 3,31; 2:; lwz 0,0x224(1); mtspr 8,0; lmw 29,0x214(1); addi 1,1,544"
extern "C" void _s801B2C14_0();
extern "C" void _s801B2C14_1();
extern "C" void _s801B2C14_2();
extern "C" void _s801B2C14_3();
extern "C" void _s801B2C14_4();
extern "C" void f_801B2C14() {}
