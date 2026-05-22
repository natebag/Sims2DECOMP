// 0x80272884 TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_802728B0" lines="bl _s80272884_0; stw 26,0x0(27); cmpwi 31,0; lhz 9,-6476(30); addi 9,9,1; sth 9,-6476(30)"
extern "C" void _s80272884_0();
extern "C" void f_802728B0();
extern "C" void f_80272884() {}
