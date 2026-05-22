// 0x801B29F8 FAMTarget::GoUpMenuTree(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; addi 11,31,160; addi 3,31,144; lwz 9,0xc(11); lwz 10,0xc(3); lwz 8,0x4(11); subf 9,10,9; lwz 0,0xa0(31); srawi 9,9,2; lwz 11,0x8(3); lwz 10,0x90(31); subf 0,8,0; addi 9,9,-1; srawi 0,0,2; subf 11,10,11; rlwinm 9,9,5,0,26; add 9,9,0; srawi 11,11,2; add 9,9,11; cmpwi 9,1; beq 3f; li 0,0; stw 0,0xc0(31); lwz 9,0x10(3); lwz 0,0x14(3); cmpw 9,0; beq 0f; addi 0,9,-4; stw 0,0x10(3); b 1f; 0:; bl _s801B29F8_0; 1:; addi 9,31,160; lwz 10,0xa0(31); lwz 11,0x4(9); addi 7,1,8; lwz 8,0xc(9); lwz 0,0x8(9); cmpw 10,11; stw 10,0x8(1); stw 0,0x10(1); stw 11,0xc(1); stw 8,0x14(1); bne 2f; addi 0,8,-4; stw 0,0x14(1); lwz 9,-4(8); addi 11,9,128; stw 9,0xc(1); stw 11,0x10(1); lwz 0,0x8(7); stw 0,0x8(1); 2:; lwz 9,0x8(1); mr 3,31; addi 0,9,-4; stw 0,0x8(1); lwz 4,-4(9); bl _s801B29F8_1; 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801B29F8_0();
extern "C" void _s801B29F8_1();
extern "C" void f_801B29F8() {}
