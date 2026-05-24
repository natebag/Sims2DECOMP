// 0x801BBA58 INGTarget::update_item_states(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 30,0; addi 31,29,432; 0:; lwz 4,0x0(31); mr 3,29; addi 31,31,4; bl _s801BBA58_0; mr 5,3; mr 4,30; mr 3,29; addi 30,30,1; bl _s801BBA58_1; cmplwi 30,11; ble 0b; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801BBA58_0();
extern "C" void _s801BBA58_1();

struct INGTarget {
    void update_item_states();
};

void INGTarget::update_item_states() {
}
