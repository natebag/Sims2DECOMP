// 0x801B2B00 FAMTarget::GetNameForFamilyInLotSelect(char (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); lwz 4,0x14c(3); mr 31,5; bl _s801B2B00_0; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x128(9); lwz 0,0x12c(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; bne 1f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,1924; addi 3,1,16; crxor 6,6,6; bl _s801B2B00_1; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,31; bl _s801B2B00_2; b 2f; 1:; lwz 9,0x0(11); li 4,0; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); lwz 4,0x0(3); lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 2f; lwz 3,0xc(3); bl _s801B2B00_3; mr 4,3; li 6,-1; li 5,0; addi 3,1,8; bl _s801B2B00_4; addi 3,1,8; bl _s801B2B00_5; mr 4,3; mr 3,31; bl _s801B2B00_6; addi 3,1,8; li 4,2; bl _s801B2B00_7; 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801B2B00_0();
extern "C" void _s801B2B00_1();
extern "C" void _s801B2B00_2();
extern "C" void _s801B2B00_3();
extern "C" void _s801B2B00_4();
extern "C" void _s801B2B00_5();
extern "C" void _s801B2B00_6();
extern "C" void _s801B2B00_7();
extern "C" void f_801B2B00() {}
