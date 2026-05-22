// 0x80254988 OSGetIdleFunction (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32694; addi 3,3,-24360; lhz 0,0x2c8(3); cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_80254988() {}
