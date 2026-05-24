// 0x801A566C CRDTarget::InitCreditsTextFetch(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 3,10754; bl _s801A566C_0; mr 0,3; li 4,0; li 5,10754; stw 0,0xb8(31); bl _s801A566C_1; lis 4,-32697; lis 5,-32705; addi 4,4,24012; lwz 30,0xb8(31); addi 5,5,-7764; addi 3,1,8; crxor 6,6,6; bl _s801A566C_2; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s801A566C_3; lwz 9,0xb8(31); li 0,1; stw 0,0xb0(31); stw 9,0xbc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s801A566C_0();
extern "C" void _s801A566C_1();
extern "C" void _s801A566C_2();
extern "C" void _s801A566C_3();

struct CRDTarget {
    void InitCreditsTextFetch();
};

void CRDTarget::InitCreditsTextFetch() {
}
