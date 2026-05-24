// 0x801C1BE8 M2MTarget::GetItemTextSaveGameSelect(int, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); rlwinm 4,4,2,0,29; lis 9,-32705; addi 4,4,312; mr 29,5; add 30,3,4; addi 4,9,-8284; mr 3,30; bl _s801C1BE8_0; mr 3,30; bl _s801C1BE8_1; mr 4,3; mr 3,29; bl _s801C1BE8_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801C1BE8_0();
extern "C" void _s801C1BE8_1();
extern "C" void _s801C1BE8_2();

struct M2MTarget {
    void GetItemTextSaveGameSelect();
};

void M2MTarget::GetItemTextSaveGameSelect() {
}
