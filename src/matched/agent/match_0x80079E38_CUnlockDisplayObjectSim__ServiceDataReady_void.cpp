// 0x80079E38 CUnlockDisplayObjectSim::ServiceDataReady(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; lwz 0,0x8c(31); cmpwi 0,0; beq 0f; lwz 0,0x10(31); cmpwi 0,0; beq 0f; lwz 0,0x34(31); cmpwi 0,0; bne 1f; 0:; li 30,0; 1:; lwz 3,0x8c(31); bl _s80079E38_0; lwz 3,0x8c(31); bl _s80079E38_1; cmpwi 3,0; beq 2f; li 30,0; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80079E38_0();
extern "C" void _s80079E38_1();
extern "C" void f_80079E38() {}
