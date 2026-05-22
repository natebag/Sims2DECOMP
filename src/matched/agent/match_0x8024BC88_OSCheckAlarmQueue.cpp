// 0x8024BC88 OSCheckAlarmQueue (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32700; stw 0,0x4(1); addi 4,3,-21176; stwu 1,-8(1); lwz 5,-23688(13); cmplwi 5,0; bne 0f; addi 3,13,-23688; lwz 0,0x4(3); cmplwi 0,0; beq 2f; 0:; cmplwi 5,0; beq 1f; addi 3,13,-23688; lwz 0,0x4(3); cmplwi 0,0; bne 2f; 1:; addi 3,4,16; crxor 6,6,6; li 4,146; bl _s8024BC88_0; li 3,0; b 9f; 2:; cmplwi 5,0; beq 3f; lwz 0,0x10(5); cmplwi 0,0; beq 3f; addi 3,4,156; crxor 6,6,6; li 4,147; bl _s8024BC88_1; li 3,0; b 9f; 3:; addi 3,13,-23688; lwz 3,0x4(3); cmplwi 3,0; beq 4f; lwz 0,0x14(3); cmplwi 0,0; beq 4f; addi 3,4,248; crxor 6,6,6; li 4,148; bl _s8024BC88_2; li 3,0; b 9f; 4:; mr 6,5; b 8f; 5:; lwz 5,0x14(6); cmplwi 5,0; beq 6f; lwz 0,0x10(5); cmplw 0,6; beq 6f; addi 3,4,340; crxor 6,6,6; li 4,151; bl _s8024BC88_3; li 3,0; b 9f; 6:; cmplwi 5,0; bne 7f; cmplw 3,6; beq 7f; addi 3,4,424; crxor 6,6,6; li 4,152; bl _s8024BC88_4; li 3,0; b 9f; 7:; mr 6,5; 8:; cmplwi 6,0; bne 5b; li 3,1; 9:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024BC88_0();
extern "C" void _s8024BC88_1();
extern "C" void _s8024BC88_2();
extern "C" void _s8024BC88_3();
extern "C" void _s8024BC88_4();
extern "C" void f_8024BC88() {}
