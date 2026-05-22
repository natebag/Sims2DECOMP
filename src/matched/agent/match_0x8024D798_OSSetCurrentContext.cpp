// 0x8024D798 OSSetCurrentContext (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32768; stw 3,0xd4(4); rlwinm 5,3,0,2,31; stw 5,0xc0(4); lwz 5,0xd8(4); cmpw 5,3; bne 0f; lwz 6,0x19c(3); ori 6,6,8192; stw 6,0x19c(3); mfmsr 6; ori 6,6,2; mtmsr 6; blr; 0:; lwz 6,0x19c(3); rlwinm 6,6,0,19,17; stw 6,0x19c(3); mfmsr 6; rlwinm 6,6,0,19,17; ori 6,6,2; mtmsr 6; isync"
extern "C" void f_8024D798() {}
