// 0x801B708C G2DTarget::ServiceG2DShutdown(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x134(31); li 3,0; cmpwi 0,2; bgt 0f; cmpwi 0,1; bge 2f; b 3f; 0:; cmpwi 0,3; bne 1f; mr 3,31; bl _s801B708C_0; b 2f; 1:; cmpwi 0,6; bgt 3f; 2:; li 3,1; 3:; lwz 0,0x98(31); cmpwi 0,0; beq 4f; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801B708C_0();

struct G2DTarget {
    void ServiceG2DShutdown();
};

void G2DTarget::ServiceG2DShutdown() {
}
