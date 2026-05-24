// 0x801CFF44 O2TTarget::ShowHelp(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 0,0x254(31); lwz 3,0x5f10(9); cmpwi 0,0; bne 0f; lwz 0,0x90(31); cmpwi 0,0; bne 0f; lwz 0,0x248(31); cmpwi 0,0; bne 0f; li 4,47; bl _s801CFF44_0; cmpwi 3,0; bne 0f; lis 5,-32705; lwz 4,0x1b4(31); addi 5,5,16200; addi 3,31,448; li 6,0; li 7,1; li 8,0; bl _s801CFF44_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801CFF44_0();
extern "C" void _s801CFF44_1();

struct O2TTarget {
    void ShowHelp();
};

void O2TTarget::ShowHelp() {
}
