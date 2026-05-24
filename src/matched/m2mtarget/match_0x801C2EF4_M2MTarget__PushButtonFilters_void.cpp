// 0x801C2EF4 M2MTarget::PushButtonFilters(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; lwz 0,0x190(31); cmpwi 0,1; bne 0f; li 0,0; lwz 4,0x7c(31); stw 0,0x170(31); li 3,1; bl _s801C2EF4_0; stw 3,0x174(31); b 1f; 0:; lwz 4,0x7c(31); li 3,0; bl _s801C2EF4_1; li 0,0; stw 3,0x170(31); stw 0,0x174(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801C2EF4_0();
extern "C" void _s801C2EF4_1();

struct M2MTarget {
    void PushButtonFilters();
};

void M2MTarget::PushButtonFilters() {
}
