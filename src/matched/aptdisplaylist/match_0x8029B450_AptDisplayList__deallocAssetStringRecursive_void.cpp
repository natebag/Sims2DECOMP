// 0x8029B450 AptDisplayList::deallocAssetStringRecursive(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stw 31,0x94(1); stw 0,0x9c(1); lwz 9,0x0(3); li 0,0; lwz 11,0x0(9); lwz 31,0x54(11); stw 0,0x88(1); cmpwi 31,0; beq 1f; 0:; mr 3,31; bl _s8029B450_0; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x9c(1); mtspr 8,0; lwz 31,0x94(1); addi 1,1,152"

extern "C" void _s8029B450_0();

struct AptDisplayList {
    void deallocAssetStringRecursive();
};

void AptDisplayList::deallocAssetStringRecursive() {
}
