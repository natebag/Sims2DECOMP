// 0x801D1C40 sort_cellinfo_by_cost(void (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 0,3; mr 31,4; cmpw 0,31; li 3,0; beq 0f; mr 3,0; bl _s801D1C40_0; mr 30,3; mr 3,31; bl _s801D1C40_1; cmpw 30,3; li 3,0; beq 0f; li 3,1; bge 0f; li 3,-1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801D1C40_0();
extern "C" void _s801D1C40_1();
extern "C" void f_801D1C40() {}
