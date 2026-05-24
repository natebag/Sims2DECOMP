// 0x802318F0 ERLevel::Write(EStream (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 22,0x40(1); stw 0,0x6c(1); mr 29,4; mr 26,3; bl _s802318F0_0; addis 28,26,3; lwz 11,0x18(29); li 9,0; li 0,38; stw 9,0x10(1); stw 9,0x8(1); addi 4,1,24; stw 9,0xc(1); li 5,4; stw 0,0x18(1); addi 25,1,48; lwz 0,0x3c(11); addi 24,1,52; lha 3,0x38(11); addi 23,1,56; mtspr 8,0; addi 22,1,60; add 3,29,3; li 27,0; blrl; lwz 9,0x18(29); addi 4,1,28; li 5,4; lwz 0,0x8(1); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x1c(1); mtspr 8,9; blrl; lwz 9,0x18(29); addi 4,1,32; li 5,4; lwz 0,0xc(1); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x20(1); mtspr 8,9; blrl; lwz 9,0x18(29); addi 4,1,36; li 5,4; lwz 0,0x10(1); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x24(1); mtspr 8,9; blrl; addi 4,28,-23948; mr 3,29; bl _s802318F0_1; lwz 9,0x18(29); addi 4,1,40; li 5,4; lwz 0,-25228(28); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x28(1); mtspr 8,9; blrl; lwz 9,0x18(29); addi 4,1,44; li 5,4; lwz 0,-25012(28); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x2c(1); mtspr 8,9; blrl; lwz 0,-25012(28); cmpw 27,0; bge 1f; mr 30,28; addi 31,30,-25008; 0:; lwz 4,0x0(31); mr 3,29; addi 27,27,1; addi 31,31,4; bl _s802318F0_2; lwz 0,-25012(30); cmpw 27,0; blt 0b; 1:; lwz 9,0x18(29); addis 30,26,3; mr 4,25; li 5,4; lha 3,0x38(9); li 27,0; lwz 9,0x3c(9); mr 31,30; add 3,29,3; lwz 0,-25224(30); mtspr 8,9; stw 0,0x30(1); blrl; lwz 9,0x18(29); mr 4,24; li 5,4; lwz 0,-25220(30); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x34(1); mtspr 8,9; blrl; lwz 9,0x18(29); mr 4,23; li 5,4; lwz 0,-25216(30); lha 3,0x38(9); lwz 9,0x3c(9); add 3,29,3; stw 0,0x38(1); mtspr 8,9; blrl; lwz 0,-25216(30); cmpw 27,0; bge 3f; mr 28,31; addi 30,31,-25212; 2:; lwz 4,0x0(30); mr 3,29; addi 27,27,1; addi 30,30,4; bl _s802318F0_3; lwz 0,-25216(28); cmpw 27,0; blt 2b; 3:; lwz 9,0x18(29); mr 4,22; li 5,4; lwz 0,-15688(31); lha 3,0x38(9); li 28,0; lwz 9,0x3c(9); add 3,29,3; stw 0,0x3c(1); mtspr 8,9; blrl; lwz 0,-15688(31); cmpw 28,0; bge 5f; mr 30,31; addi 31,30,-23880; 4:; lwz 4,0x0(31); mr 3,29; addi 28,28,1; addi 31,31,4; bl _s802318F0_4; lwz 0,-15688(30); cmpw 28,0; blt 4b; 5:; lwz 0,0x6c(1); mtspr 8,0; lmw 22,0x40(1); addi 1,1,104"

extern "C" void _s802318F0_0();
extern "C" void _s802318F0_1();
extern "C" void _s802318F0_2();
extern "C" void _s802318F0_3();
extern "C" void _s802318F0_4();

struct ERLevel {
    void Write();
};

void ERLevel::Write() {
}
