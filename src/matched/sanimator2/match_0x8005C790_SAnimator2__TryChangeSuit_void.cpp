// 0x8005C790 SAnimator2::TryChangeSuit(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x8(31); lwz 0,0x638(9); cmpwi 0,0; bne 0f; li 3,0; b 3f; 0:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x160(9); lwz 9,0x164(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 9,0x8(31); li 0,0; li 3,0; li 4,1; stw 0,0x3d8(9); b 4f; 1:; lwz 11,0x4(31); li 4,8; lwz 9,0x4(11); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x130(31); cmpw 0,3; bne 2f; lwz 3,0x8(31); bl _s8005C790_0; mr. 3,3; bne 2f; lwz 9,0x8(31); lwz 0,0x630(9); cmpwi 0,-1; bne 2f; stw 3,0x3d8(9); li 3,0; li 4,1; b 4f; 2:; lwz 9,0x8(31); li 0,1; li 3,0; stw 0,0x3d8(9); 3:; li 4,2; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8005C790_0();

struct SAnimator2 {
    void TryChangeSuit();
};

void SAnimator2::TryChangeSuit() {
}
