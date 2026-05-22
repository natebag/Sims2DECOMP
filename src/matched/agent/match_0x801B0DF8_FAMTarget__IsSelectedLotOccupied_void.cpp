// 0x801B0DF8 FAMTarget::IsSelectedLotOccupied(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x14c(31); bl _s801B0DF8_0; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x128(9); lwz 0,0x12c(9); add 3,11,3; mtspr 8,0; blrl; mr. 4,3; li 3,0; beq 0f; mr 3,31; bl _s801B0DF8_1; cmpwi 3,0; li 3,1; bgt 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801B0DF8_0();
extern "C" void _s801B0DF8_1();
extern "C" void f_801B0DF8() {}
