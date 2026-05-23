// 0x800670E0 SAnimator2::setJobModel(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 10,-21412(13); mr 31,3; cmpwi 10,0; beq 0f; lwz 11,0x4(31); li 4,56; lwz 30,0x0(10); lwz 9,0x4(11); lha 29,0x20(30); lwz 0,0x13c(9); addi 30,30,32; lha 3,0x138(9); add 29,10,29; mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 30,3; beq 0f; lwz 11,0x4(31); li 4,57; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; mulli 3,3,112; lwz 9,0x4(30); add 9,9,3; lwz 4,0x68(9); cmpwi 4,0; beq 0f; lbz 0,0x0(4); cmpwi 0,0; beq 0f; mr 3,31; li 5,0; li 6,1; bl _s800670E0_0; b 1f; 0:; mr 3,31; bl _s800670E0_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800670E0_0();
extern "C" void _s800670E0_1();

struct SAnimator2 {
    void setJobModel();
};

void SAnimator2::setJobModel() {
}
