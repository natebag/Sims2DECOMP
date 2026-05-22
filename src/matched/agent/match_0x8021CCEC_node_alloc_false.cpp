// 0x8021CCEC __node_alloc<false, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 3,11,3; mtspr 8,0; blrl; mr 4,31; bl _s8021CCEC_0; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021CCEC_0();
extern "C" int f_8021CCEC() {}
