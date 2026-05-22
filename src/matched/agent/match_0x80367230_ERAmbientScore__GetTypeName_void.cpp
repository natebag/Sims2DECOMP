// 0x80367230 ERAmbientScore::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-10392(9)"
extern "C" int f_80367230() {}
