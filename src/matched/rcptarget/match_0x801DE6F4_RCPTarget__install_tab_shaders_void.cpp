// 0x801DE6F4 RCPTarget::install_tab_shaders(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 29,0; lwz 0,0x12c(31); cmplw 29,0; bge 4f; lis 11,-32705; lis 9,-32705; addi 28,9,31932; addi 30,11,31740; 0:; lwz 0,0x130(31); cmpw 29,0; bne 1f; lwz 5,0x4(30); b 2f; 1:; lwz 5,0x0(30); 2:; lwz 0,0x0(31); lwz 4,0x0(28); cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801DE6F4_0; 3:; lwz 0,0x12c(31); addi 29,29,1; addi 28,28,4; addi 30,30,8; cmplw 29,0; blt 0b; 4:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801DE6F4_0();

struct RCPTarget {
    void install_tab_shaders();
};

void RCPTarget::install_tab_shaders() {
}
