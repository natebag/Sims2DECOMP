// 0x801D5D28 PCTTarget::update_grid_shaders(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 11,-32705; lis 9,-32705; mr 30,3; addi 27,9,30244; addi 28,11,30004; li 29,0; 0:; mr 3,30; mr 4,29; bl _s801D5D28_0; lis 31,-24685; lwz 0,0xc0(30); lis 5,-24685; ori 31,31,65396; ori 5,5,65396; cmplw 3,0; bge 2f; mulli 9,3,24; lwz 0,0xbc(30); add. 9,0,9; beq 2f; lwz 0,0xc(9); lwz 5,0x8(9); cmpwi 0,0; beq 1f; lis 31,14402; ori 31,31,19756; b 2f; 1:; lwz 0,0x10(9); cmpwi 0,0; beq 2f; lis 31,-28459; ori 31,31,26562; 2:; lwz 0,0x0(30); lwz 4,0x0(28); cmpwi 0,0; beq 3f; lwz 3,0x1c(30); cmpwi 3,0; beq 3f; lwz 6,0x7c(30); li 7,0; bl _s801D5D28_1; 3:; lwz 0,0x0(30); lwz 4,0x0(27); cmpwi 0,0; beq 4f; lwz 3,0x1c(30); cmpwi 3,0; beq 4f; lwz 6,0x7c(30); mr 5,31; li 7,0; bl _s801D5D28_2; 4:; addi 29,29,1; addi 27,27,4; addi 28,28,4; cmplwi 29,11; ble 0b; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801D5D28_0();
extern "C" void _s801D5D28_1();
extern "C" void _s801D5D28_2();

struct PCTTarget {
    void update_grid_shaders();
};

void PCTTarget::update_grid_shaders() {
}
