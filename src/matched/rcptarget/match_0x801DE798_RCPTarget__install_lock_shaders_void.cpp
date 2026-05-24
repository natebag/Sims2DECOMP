// 0x801DE798 RCPTarget::install_lock_shaders(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32705; mr 31,3; addi 29,9,32012; li 30,0; 0:; lwz 9,0x134(31); lis 5,-24685; lwz 0,0x128(31); ori 5,5,65396; add 9,9,30; cmplw 9,0; bge 2f; mulli 0,9,20; lwz 9,0x124(31); add 9,0,9; lwz 11,0x8(9); cmpwi 11,0; beq 1f; lis 5,-30482; ori 5,5,20783; b 2f; 1:; lwz 0,0xc(9); cmpwi 0,0; beq 2f; lis 5,13088; ori 5,5,34217; 2:; lwz 0,0x0(31); lwz 4,0x0(29); cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801DE798_0; 3:; addi 30,30,1; addi 29,29,4; cmplwi 30,2; ble 0b; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801DE798_0();

struct RCPTarget {
    void install_lock_shaders();
};

void RCPTarget::install_lock_shaders() {
}
