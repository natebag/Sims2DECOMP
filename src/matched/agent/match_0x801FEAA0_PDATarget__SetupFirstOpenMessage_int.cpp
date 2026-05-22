// 0x801FEAA0 PDATarget::SetupFirstOpenMessage(int, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subfic 9,5,13; subfe 9,9,9; neg. 9,9; bnelr; cmpwi 4,2; bne 0f; stw 5,-28524(13); li 9,1; stw 5,-28520(13); 0:; cmpwi 9,0; bnelr; rlwinm 0,4,2,0,29; addi 9,13,-28524; stwx 5,9,0"
extern "C" void f_801FEAA0() {}
