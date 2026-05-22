// 0x8036E220 tolower (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; addi 9,9,-935; lbzx 0,3,9; andi. 9,0,1; beqlr; addi 3,3,32"
extern "C" int f_8036E220() {}
