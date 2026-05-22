// 0x800374AC EyeToyClient::saveTexture(int, (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,4; li 0,0; cmpwi 3,4; stw 0,0x0(31); stw 0,0x4(31); bgt 2f; mulli 3,3,12; lis 9,-32702; addi 9,9,15808; add 11,3,9; lwz 0,0x8(11); cmpwi 0,0; beq 2f; lwzx 3,3,9; cmpwi 3,0; beq 2f; lwz 3,0x4(3); cmpwi 3,0; beq 2f; lwz 0,0x14(3); cmpwi 0,0; beq 0f; mr 3,0; b 1f; 0:; lwz 9,0x18(3); li 3,0; cmpwi 9,0; beq 1f; lwz 3,0x14(9); 1:; cmpwi 3,0; beq 2f; li 4,0; bl _s800374AC_0; mr. 11,3; beq 2f; lwz 9,0x24(11); li 4,0; addi 5,1,8; addi 6,1,12; lha 3,0x40(9); li 0,0; lwz 9,0x44(9); add 3,11,3; stw 0,0xc(1); mtspr 8,9; stw 0,0x8(1); blrl; lwz 0,0x8(1); lwz 9,0xc(1); stw 3,0x4(31); mullw 0,0,9; stw 0,0x0(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800374AC_0();
extern "C" void f_800374AC() {}
