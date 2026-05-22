// 0x803871DC __GXDefaultTlutRegionCallback (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,20; blt 0f; li 3,0; b 1f; 0:; rlwinm 3,3,4,0,27; lwz 0,-17720(13); addi 3,3,904; add 3,0,3; 1:"
extern "C" int f_803871DC() {}
