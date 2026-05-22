// 0x8026732C AISetStreamVolLeft (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; addi 4,4,27648; lwz 0,0x4(4); clrlwi 0,0,23; rlwimi 0,3,0,24,31; stw 0,0x4(4)"
extern "C" void f_8026732C() {}
