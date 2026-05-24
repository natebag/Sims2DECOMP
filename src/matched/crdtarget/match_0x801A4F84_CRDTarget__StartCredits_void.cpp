// 0x801A4F84 CRDTarget::StartCredits(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0xa0(31); cmpwi 0,0; beq 0f; cmpwi 0,1; bne 1f; mr 3,31; bl _s801A4F84_0; 0:; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; stfs f1,0xa4(31); 1:; li 9,1; li 0,0; stw 0,0x9c(31); stw 9,0xa0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801A4F84_0();

struct CRDTarget {
    void StartCredits();
};

void CRDTarget::StartCredits() {
}
