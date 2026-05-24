// 0x801D6218 PCTTarget::can_afford_selection(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 4,0xb8(3); bl _s801D6218_0; mr. 31,3; li 3,0; beq 1f; bl _s801D6218_1; mr 30,3; mr 3,31; bl _s801D6218_2; lwz 0,0xc(31); cmpw cr7,3,30; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; cmpwi 0,0; beq 0f; li 3,0; 0:; lis 9,-32697; lwz 0,0x6188(9); cmpwi 0,0; beq 1f; li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801D6218_0();
extern "C" void _s801D6218_1();
extern "C" void _s801D6218_2();

struct PCTTarget {
    void can_afford_selection();
};

void PCTTarget::can_afford_selection() {
}
