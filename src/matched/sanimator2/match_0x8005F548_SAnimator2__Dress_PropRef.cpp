// 0x8005F548 SAnimator2::Dress(PropRef (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s8005F548_0; mr. 29,3; beq 1f; lwz 9,0x0(31); mr 4,30; lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); li 5,1; lbz 11,0xc(30); lha 0,0x140(9); addi 10,9,320; cmpwi 11,0; add 3,31,0; bne 0f; li 5,0; 0:; lwz 0,0x4(10); mr 4,29; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8005F548_0();

struct SAnimator2 {
    void Dress();
};

void SAnimator2::Dress() {
}
