// 0x80312984 EResPrefetch::DoFlush(EPrefetchMsg (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; b 1f; 0:; mr 3,31; bl _s80312984_0; 1:; lwz 0,0x414(31); cmpwi 0,0; bne 0b; lwz 3,0x10(30); cmpwi 3,0; beq 2f; bl _s80312984_1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80312984_0();
extern "C" void _s80312984_1();

struct EResPrefetch {
    void DoFlush_EPrefetchMsg();
};

void EResPrefetch::DoFlush_EPrefetchMsg() {
}
