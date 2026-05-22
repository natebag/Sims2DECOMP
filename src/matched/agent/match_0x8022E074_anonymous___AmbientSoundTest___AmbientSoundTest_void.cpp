// 0x8022E074 {anonymous}::AmbientSoundTest::~AmbientSoundTest(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,-19456; blr; lis 9,-32688; lwz 3,-19444(9); blr; lis 9,-32688; lwz 3,-19440(9)"
extern "C" int f_8022E074() {}
