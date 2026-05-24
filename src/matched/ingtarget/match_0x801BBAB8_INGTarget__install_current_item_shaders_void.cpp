// 0x801BBAB8 INGTarget::install_current_item_shaders(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32705; mr 31,3; addi 30,9,27784; addi 29,31,432; addi 28,30,44; 0:; lwz 9,0x0(29); addi 29,29,4; cmpwi 9,0; beq 1f; lwz 3,0x0(9); cmpwi 3,0; beq 1f; lwz 5,0x8(3); b 2f; 1:; mr 3,31; bl _s801BBAB8_0; mr 5,3; 2:; lwz 0,0x0(31); lwz 4,0x0(30); cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801BBAB8_1; 3:; addi 30,30,4; cmplw 30,28; ble 0b; mr 3,31; bl _s801BBAB8_2; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801BBAB8_0();
extern "C" void _s801BBAB8_1();
extern "C" void _s801BBAB8_2();

struct INGTarget {
    void install_current_item_shaders();
};

void INGTarget::install_current_item_shaders() {
}
