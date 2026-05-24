// 0x80284344 AptAnimationPoolData::addInput(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 9,0x34(3); mr 8,4; lwz 0,0xa4(3); cmpw 9,0; bge 1f; rlwinm 10,9,2,0,29; cmpwi 9,0; lwz 11,0x38(3); ble 0f; add 9,10,11; lwz 0,-4(9); cmpw 0,8; beq 1f; 0:; stwx 8,10,11; lwz 0,-27608(13); lwz 9,0x34(3); cmpwi 0,0; addi 9,9,1; stw 9,0x34(3); beq 1f; lis 11,-32694; addi 9,1,8; lwz 11,-16264(11); mr 3,9; lwz 0,-23012(13); li 4,8; mtspr 8,11; stw 0,0x8(1); stw 8,0x4(9); blrl; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

struct AptAnimationPoolData {
    void addInput();
};

void AptAnimationPoolData::addInput() {
}
