// 0x80312DB0 EResPrefetch::CanAddRef(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32692; lwz 0,-17456(9); li 9,0; cmpw 3,0; bne 0f; lwz 0,0x414(3); subfic 11,0,0; adde 9,11,0; 0:; cmpwi 9,0; li 10,0; beq 3f; lwz 11,0x3f0(3); lwz 9,0x400(3); cmplw 11,9; bge 1f; lwz 0,0x404(3); cmpw 0,11; beq 2f; b 3f; 1:; lwz 0,0x404(3); cmpw 0,9; bne 3f; 2:; li 10,1; 3:; mr 3,10"

struct EResPrefetch {
    void CanAddRef();
};

void EResPrefetch::CanAddRef() {
}
