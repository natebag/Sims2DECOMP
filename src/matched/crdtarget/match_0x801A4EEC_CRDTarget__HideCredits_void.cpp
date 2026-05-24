// 0x801A4EEC CRDTarget::HideCredits(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; addi 3,1,8; bl _s801A4EEC_0; lwz 0,0x88(31); cmpwi 0,0; beq 0f; lwz 0,0x8c(31); cmpwi 0,0; bne 0f; lis 4,-32705; lis 7,-32705; addi 3,1,8; addi 7,7,-7956; li 5,250; li 6,0; li 8,0; addi 4,4,-7816; bl _s801A4EEC_1; addi 3,1,8; li 4,0; bl _s801A4EEC_2; addi 3,1,8; bl _s801A4EEC_3; li 0,1; stw 0,0x8c(31); 0:; addi 3,1,8; li 4,2; bl _s801A4EEC_4; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"

extern "C" void _s801A4EEC_0();
extern "C" void _s801A4EEC_1();
extern "C" void _s801A4EEC_2();
extern "C" void _s801A4EEC_3();
extern "C" void _s801A4EEC_4();

struct CRDTarget {
    void HideCredits();
};

void CRDTarget::HideCredits() {
}
