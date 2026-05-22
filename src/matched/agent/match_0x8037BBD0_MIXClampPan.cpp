// 0x8037BBD0 __MIXClampPan (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; bge 0f; li 3,0; blr; 0:; cmpwi 3,127; blelr; li 3,127"
extern "C" int f_8037BBD0() {}
