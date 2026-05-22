// 0x8039B714 __VMBASESetupVMRegisters (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; li 3,0; stw 0,0x14(1); .long 0x7C0704A6; mtsr 7,3; stw 0,-21516(13); mfmsr 3; mfspr 4,25; lwz 0,-21536(13); rlwinm 5,4,0,16,31; stw 4,-21512(13); rlwinm 0,0,0,1,15; rlwinm 3,3,0,28,25; add 4,5,0; li 5,0; bl _s8039B714_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B714_0();
extern "C" void f_8039B714() {}
