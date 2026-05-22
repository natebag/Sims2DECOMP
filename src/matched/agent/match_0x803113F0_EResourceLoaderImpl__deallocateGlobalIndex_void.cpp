// 0x803113F0 EResourceLoaderImpl::deallocateGlobalIndex(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 28,0; addi 31,29,852; li 30,2; 0:; lwz 0,0x0(31); cmpwi 0,0; beq 1f; bl _s803113F0_0; lwz 4,0x0(31); bl _s803113F0_1; stw 28,0x0(31); 1:; addi 31,31,4; addic. 30,30,-1; bne 0b; lwz 3,0x348(29); cmpwi 3,0; beq 3f; li 0,0; 2:; stw 0,0x4c(3); lwz 3,0xd04(3); cmpwi 3,0; bne 2b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803113F0_0();
extern "C" void _s803113F0_1();
extern "C" void f_803113F0() {}
