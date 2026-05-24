// 0x801838B0 ActionMenu::Animate(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 0,0x9(31); cmpwi 0,5; bne 0f; lhz 11,0x6(31); lbz 9,0xa2(31); extsh 0,11; addi 9,9,-1; cmpw 0,9; bge 2f; addi 0,11,1; b 1f; 0:; lhz 9,0x6(31); cmpwi 9,0; beq 2f; addi 0,9,-1; 1:; sth 0,0x6(31); 2:; mr 3,31; bl _s801838B0_0; li 0,4; stb 0,0x9(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801838B0_0();

struct ActionMenu {
    void Animate();
};

void ActionMenu::Animate() {
}
