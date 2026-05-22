// 0x80392554 VMStoreAllPages (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; lis 3,-32711; stw 0,0x14(1); addi 3,3,9376; bl _s80392554_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392554_0();
extern "C" void f_80392554() {}
