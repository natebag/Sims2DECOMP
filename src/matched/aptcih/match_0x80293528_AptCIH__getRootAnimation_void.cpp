// 0x80293528 AptCIH::getRootAnimation(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; b 2f; 0:; mr 3,31; li 30,0; bl _s80293528_0; cmpwi 3,19; bne 1f; mr 3,31; bl _s80293528_1; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; bne 4f; lwz 31,0x48(31); 2:; mr 3,31; li 30,0; bl _s80293528_2; cmpwi 3,18; bne 3f; mr 3,31; bl _s80293528_3; subfic 0,3,0; adde 30,0,3; 3:; cmpwi 30,0; beq 0b; 4:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80293528_0();
extern "C" void _s80293528_1();
extern "C" void _s80293528_2();
extern "C" void _s80293528_3();

struct AptCIH {
    void getRootAnimation();
};

void AptCIH::getRootAnimation() {
}
