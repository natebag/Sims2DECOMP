// 0x8037B49C __node_alloc<false, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(30); ori 0,0,16384; stw 0,0x1c(30); bl _s8037B49C_0; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037B49C_0();
extern "C" void f_8037B49C() {}
