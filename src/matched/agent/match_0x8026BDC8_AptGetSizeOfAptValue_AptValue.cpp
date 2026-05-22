// 0x8026BDC8 AptGetSizeOfAptValue(AptValue (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 0,0,0,25,31; cmpwi 0,37; beq 0f; lis 9,-32704; addi 9,9,3732; lbzx 3,9,0; blr; 0:; lwz 3,0x10(3)"
extern "C" int f_8026BDC8() {}
