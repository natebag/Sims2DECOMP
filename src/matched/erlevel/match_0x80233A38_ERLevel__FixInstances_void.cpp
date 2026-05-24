// 0x80233A38 ERLevel::FixInstances(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; li 29,0; addis 31,27,3; lwz 0,-15688(31); cmpw 29,0; bge 1f; li 28,0; 0:; addi 9,31,-23880; mr 30,31; lwzx 11,9,28; addi 29,29,1; addi 28,28,4; lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-15688(30); cmpw 29,0; blt 0b; 1:; addis 30,27,3; li 0,0; stw 0,-7476(30); mr 3,27; addi 4,30,-23900; mr 26,30; bl _s80233A38_0; li 31,0; mr 3,27; addi 4,30,-23912; bl _s80233A38_1; lwz 0,-23884(30); addic. 9,0,1; ble 4f; li 28,0; li 29,0; 2:; lwz 4,-23936(30); mr 3,27; add 4,4,29; bl _s80233A38_2; lwz 9,-23932(30); lwzx 11,28,9; cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; 3:; lwz 9,-23884(26); addi 31,31,1; addi 28,28,4; addi 29,29,12; addi 9,9,1; cmpw 31,9; blt 2b; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80233A38_0();
extern "C" void _s80233A38_1();
extern "C" void _s80233A38_2();

struct ERLevel {
    void FixInstances();
};

void ERLevel::FixInstances() {
}
