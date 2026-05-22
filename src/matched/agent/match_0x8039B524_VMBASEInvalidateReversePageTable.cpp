// 0x8039B524 __VMBASEInvalidateReversePageTable (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,512; li 5,0; li 4,0; mtspr 9,0; 0:; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21532(13); stwx 4,3,5; addi 5,5,4; bdnz 0b"
extern "C" void f_8039B524() {}
