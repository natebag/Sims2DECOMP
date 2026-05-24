// 0x80312C70 EResPrefetch::AddRef(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; mr 3,5; li 4,0; bl _s80312C70_0; mr 5,3; mr 4,30; mr 3,29; bl _s80312C70_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80312C70_0();
extern "C" void _s80312C70_1();

struct EResPrefetch {
    void AddRef();
};

void EResPrefetch::AddRef() {
}
