// 0x801B3130 FAMTarget::SetCurrentChoice(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,4; bl _s801B3130_0; lwz 0,0x88(31); cmpwi 0,0; bne 0f; stw 3,0x14c(31); mr 3,31; bl _s801B3130_1; b 4f; 0:; cmpwi 0,1; bne 1f; stw 3,0x160(31); b 4f; 1:; cmpwi 0,2; bne 2f; stw 3,0x164(31); b 4f; 2:; cmpwi 0,3; bne 3f; stw 3,0x15c(31); b 4f; 3:; cmpwi 0,4; bne 4f; mr 4,3; stw 3,0x150(31); mr 3,31; bl _s801B3130_2; mr. 11,3; beq 4f; lwz 9,0x0(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; lis 11,-32697; lis 9,-32697; addi 11,11,24012; stw 3,0x5c5c(9); stw 3,0x44c(11); stw 3,0x448(11); 4:; mr 3,31; bl _s801B3130_3; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801B3130_0();
extern "C" void _s801B3130_1();
extern "C" void _s801B3130_2();
extern "C" void _s801B3130_3();
extern "C" void f_801B3130() {}
