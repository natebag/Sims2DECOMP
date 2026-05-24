// 0x802906C4 AptCIH::getNativeHash(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s802906C4_0; cmpwi 3,19; bne 0f; mr 3,31; bl _s802906C4_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; li 3,0; bne 2f; lwz 3,0x4c(31); cmpwi 3,0; beq 1f; lis 0,-17747; ori 0,0,61453; cmpw 3,0; beq 1f; lwz 3,0xc(3); b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802906C4_0();
extern "C" void _s802906C4_1();

struct AptCIH {
    void getNativeHash();
};

void AptCIH::getNativeHash() {
}
