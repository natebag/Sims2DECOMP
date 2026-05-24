// 0x801E6E30 WXFTarget::ShowHelp(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x130(3); cmplwi 0,1; bgt 0f; lis 9,-32704; rlwinm 0,0,2,0,29; addi 9,9,-32504; lis 5,-32705; lwzx 6,9,0; addi 7,3,132; lis 9,-32705; lwz 4,0x94(3); addi 5,5,27124; addi 9,9,-1988; addi 3,3,160; li 8,0; bl _s801E6E30_0; b 1f; 0:; lis 9,-32704; rlwinm 0,0,2,0,29; addi 9,9,-32504; lis 5,-32705; lwzx 6,9,0; addi 7,3,132; lwz 4,0x94(3); addi 5,5,27124; addi 3,3,160; li 8,0; li 9,0; bl _s801E6E30_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801E6E30_0();
extern "C" void _s801E6E30_1();

struct WXFTarget {
    void ShowHelp();
};

void WXFTarget::ShowHelp() {
}
