// 0x8039BCFC __VMBASERestoreVMRegisters (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,-21520(13); cmpwi 0,1; bne 0f; lwz 0,-21516(13); mtsr 7,0; lwz 4,-21512(13); mfmsr 3; li 5,0; rlwinm 3,3,0,28,25; bl _s8039BCFC_0; 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039BCFC_0();
extern "C" void f_8039BCFC() {}
