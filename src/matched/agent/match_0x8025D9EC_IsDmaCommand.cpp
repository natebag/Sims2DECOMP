// 0x8025D9EC IsDmaCommand (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,1; beq 0f; addi 0,3,-4; cmplwi 0,1; ble 0f; cmplwi 3,14; bne 1f; 0:; li 3,1; blr; 1:; lwz 0,-27772(13); cmplw 3,0; bne 2f; li 3,1; blr; 2:; li 3,0"
extern "C" int f_8025D9EC() {}
