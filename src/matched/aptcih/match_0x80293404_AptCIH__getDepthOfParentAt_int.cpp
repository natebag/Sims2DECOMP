// 0x80293404 AptCIH::getDepthOfParentAt(int) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s80293404_0; cmpw 31,3; ble 0f; li 3,-1; b 3f; 0:; mr 9,30; cmpw 3,31; beq 2f; 1:; addi 3,3,-1; lwz 9,0x48(9); cmpw 3,31; bne 1b; 2:; lwz 3,0x58(9); srawi 3,3,15; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80293404_0();

struct AptCIH {
    void getDepthOfParentAt();
};

void AptCIH::getDepthOfParentAt() {
}
