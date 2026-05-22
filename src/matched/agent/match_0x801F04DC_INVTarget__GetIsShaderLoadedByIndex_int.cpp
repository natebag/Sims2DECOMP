// 0x801F04DC INVTarget::GetIsShaderLoadedByIndex(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,11; bgt 0f; rlwinm 0,4,2,0,29; addi 9,3,264; lwzx 3,9,0; blr; 0:; li 3,0"
extern "C" int f_801F04DC() {}
