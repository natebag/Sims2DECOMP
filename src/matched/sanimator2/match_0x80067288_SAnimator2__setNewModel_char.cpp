// 0x80067288 SAnimator2::setNewModel(char (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; lwz 31,0x625c(9); mr 30,4; cmpwi 31,0; li 3,0; beq 4f; lwz 3,0x8(29); bl _s80067288_0; mr 4,3; mr 5,30; mr 3,31; bl _s80067288_1; lwz 9,0x8(29); mr 30,3; lwz 10,0x3d0(9); lwz 11,0x4(10); lwz 0,0x154(11); lha 3,0x150(11); mtspr 8,0; add 3,10,3; blrl; lwz 0,0x604(29); mr 31,3; cmpwi 0,0; bne 1f; li 3,292; bl _s80067288_2; bl _s80067288_3; stw 3,0x604(29); mr 9,31; li 11,288; 0:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(3); addi 3,3,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(3); 1:; mr 3,30; mr 9,31; li 11,288; 2:; lwz 0,0x0(3); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(3); stw 0,0x4(9); lwz 0,0x8(3); stw 0,0x8(9); lwz 0,0xc(3); stw 0,0xc(9); lwz 0,0x10(3); stw 0,0x10(9); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(9); addi 9,9,24; bne 2b; lwz 0,0x0(3); li 6,1; stw 0,0x0(9); lbz 0,0x8c(31); cmpwi 0,0; bne 3f; li 6,0; 3:; lwz 5,0x604(29); mr 4,31; mr 3,29; bl _s80067288_4; mr 3,31; bl _s80067288_5; lwz 3,0x8(29); bl _s80067288_6; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80067288_0();
extern "C" void _s80067288_1();
extern "C" void _s80067288_2();
extern "C" void _s80067288_3();
extern "C" void _s80067288_4();
extern "C" void _s80067288_5();
extern "C" void _s80067288_6();

struct SAnimator2 {
    void setNewModel();
};

void SAnimator2::setNewModel() {
}
