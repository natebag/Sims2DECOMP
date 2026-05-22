// 0x8017EEA4 UIRouter::~UIRouter(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,26384; lis 11,-32697; stw 9,0x80(31); mr 30,4; mr 4,31; lwz 3,0x5e80(11); bl _s8017EEA4_0; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 0f; mr 3,31; bl _s8017EEA4_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8017EEA4_0();
extern "C" void _s8017EEA4_1();
extern "C" void f_8017EEA4() {}
