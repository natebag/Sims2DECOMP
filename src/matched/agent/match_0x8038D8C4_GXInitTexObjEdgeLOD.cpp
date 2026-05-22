// 0x8038D8C4 GXInitTexObjEdgeLOD (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm. 0,4,0,24,31; beq 0f; li 4,0; b 1f; 0:; li 4,1; 1:; lwz 0,0x0(3); rlwimi 0,4,8,23,23; stw 0,0x0(3)"
extern "C" void f_8038D8C4() {}
