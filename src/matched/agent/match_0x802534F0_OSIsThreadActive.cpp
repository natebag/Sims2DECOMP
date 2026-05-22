// 0x802534F0 __OSIsThreadActive (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x2c8(3); cmplwi 0,0; bne 0f; li 3,0; blr; 0:; lis 4,-32768; lwz 4,0xdc(4); b 3f; 1:; cmplw 3,4; bne 2f; li 3,1; blr; 2:; lwz 4,0x2fc(4); 3:; cmplwi 4,0; bne 1b; li 3,0"
extern "C" int f_802534F0() {}
