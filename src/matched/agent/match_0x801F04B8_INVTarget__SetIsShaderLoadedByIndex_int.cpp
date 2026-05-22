// 0x801F04B8 INVTarget::SetIsShaderLoadedByIndex(int, (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,11; bgt 0f; addi 9,3,264; rlwinm 0,4,2,0,29; stwx 5,9,0; li 3,1; blr; 0:; li 3,0"
extern "C" void f_801F04B8() {}
