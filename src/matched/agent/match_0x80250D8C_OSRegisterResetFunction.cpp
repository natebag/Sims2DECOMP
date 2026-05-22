// 0x80250D8C OSRegisterResetFunction (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-23632(13); b 1f; 0:; lwz 5,0x8(5); 1:; cmplwi 5,0; beq 2f; lwz 4,0x4(5); lwz 0,0x4(3); cmplw 4,0; ble 0b; 2:; cmplwi 5,0; bne 5f; addi 5,13,-23632; lwzu 4,0x4(5); cmplwi 4,0; bne 3f; stw 3,-23632(13); b 4f; 3:; stw 3,0x8(4); 4:; stw 4,0xc(3); li 0,0; stw 0,0x8(3); stw 3,0x0(5); blr; 5:; stw 5,0x8(3); lwz 4,0xc(5); stw 3,0xc(5); cmplwi 4,0; stw 4,0xc(3); bne 6f; stw 3,-23632(13); blr; 6:; stw 3,0x8(4)"
extern "C" void f_80250D8C() {}
