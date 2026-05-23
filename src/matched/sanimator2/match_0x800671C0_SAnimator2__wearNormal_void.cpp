// 0x800671C0 SAnimator2::wearNormal(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 9,0x8(31); lwz 10,0x3d0(9); lwz 11,0x4(10); lwz 0,0x154(11); lha 3,0x150(11); mtspr 8,0; add 3,10,3; blrl; lwz 0,0x604(31); cmpwi 0,0; beq 2f; mr 9,0; mr 11,3; li 30,288; 0:; lwz 0,0x0(9); addic. 30,30,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(11); bl _s800671C0_0; lwz 3,0x604(31); cmpwi 3,0; beq 1f; bl _s800671C0_1; 1:; stw 30,0x604(31); 2:; lwz 3,0x8(31); bl _s800671C0_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800671C0_0();
extern "C" void _s800671C0_1();
extern "C" void _s800671C0_2();

struct SAnimator2 {
    void wearNormal();
};

void SAnimator2::wearNormal() {
}
