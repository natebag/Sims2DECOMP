// 0x8005F82C SAnimator2::Undress(PropRef (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8005F82C_0; lwz 9,0x168(31); li 10,0; lwz 0,0x16c(31); li 4,-1; mr 11,9; subf 0,9,0; srawi 8,0,2; cmpw 10,8; bge 1f; lwz 9,0x0(11); lwz 0,0x0(9); cmpw 0,3; bne 0f; li 4,0; b 1f; 0:; addi 10,10,1; addi 11,11,4; cmpw 10,8; bge 1f; lwz 9,0x0(11); lwz 0,0x0(9); cmpw 0,3; bne 0b; mr 4,10; 1:; cmpwi 4,0; blt 2f; lwz 9,0x0(31); lha 3,0x148(9); lwz 0,0x14c(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8005F82C_0();

struct SAnimator2 {
    void Undress();
};

void SAnimator2::Undress() {
}
