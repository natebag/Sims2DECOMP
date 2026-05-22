// 0x801B5AAC G2DTarget::PopAptButtonFilters(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; addi 31,3,288; addi 28,9,24012; li 30,0; li 29,-1; 0:; lwz 0,0x0(31); mr 4,30; addi 30,30,1; mr 5,0; cmpwi 0,-1; beq 1f; lwz 3,0xb4(28); bl _s801B5AAC_0; stw 29,0x0(31); 1:; addi 31,31,4; cmpwi 30,1; ble 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801B5AAC_0();
extern "C" void f_801B5AAC() {}
