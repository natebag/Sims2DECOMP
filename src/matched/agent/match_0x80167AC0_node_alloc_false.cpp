// 0x80167AC0 __node_alloc<false, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80167B4C" lines="b 0f; lwz 10,0xc0(4); lbz 0,0xb5(4); lwz 9,0xb8(4); lwz 11,0xbc(4); 0:; stb 0,0x8(1); stw 9,0xc(1); stw 11,0x10(1); stw 10,0x14(1)"
extern "C" void f_80167B4C();
extern "C" void f_80167AC0() {}
