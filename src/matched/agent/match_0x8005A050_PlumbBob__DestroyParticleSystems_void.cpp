// 0x8005A050 PlumbBob::DestroyParticleSystems(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 30,0; lwz 0,0x1f4(29); cmpw 30,0; bge 3f; li 28,0; addi 31,29,492; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 2f; li 4,16384; li 5,1; bl _s8005A050_0; lwz 3,0x0(31); li 4,8; li 5,1; bl _s8005A050_1; lwz 11,0x0(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 28,0x0(31); 2:; lwz 0,0x1f4(29); addi 30,30,1; addi 31,31,4; cmpw 30,0; blt 0b; 3:; li 0,0; stw 0,0x1f4(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8005A050_0();
extern "C" void _s8005A050_1();
extern "C" void f_8005A050() {}
