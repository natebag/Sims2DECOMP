// 0x80293984 AptCIH::setASChanged(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; li 9,1; bne 0f; li 9,0; 0:; lwz 0,0x5c(3); rlwimi 0,9,15,16,16; stw 0,0x5c(3)"
extern "C" void f_80293984() {}
