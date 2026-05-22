// 0x80250E10 OSUnregisterResetFunction (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x8(3); lwz 5,0xc(3); cmplwi 4,0; bne 0f; addi 3,13,-23632; stw 5,0x4(3); b 1f; 0:; stw 5,0xc(4); 1:; cmplwi 5,0; bne 2f; stw 4,-23632(13); blr; 2:; stw 4,0x8(5)"
extern "C" void f_80250E10() {}
