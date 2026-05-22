// 0x80185820 ActionQueueHUD::UpdateVisual(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x150(3); li 9,0; cmplw 9,0; bgelr; lbz 11,0x168(3); mr 10,0; cmpwi 1,11,6; cmpwi 6,11,5; 0:; beq cr1,1f; lbz 0,0x308(3); cmpwi 0,0; beq 1f; lbz 0,0x309(3); cmplw 9,0; blt 1f; cmpwi 11,1; 1:; addi 9,9,1; cmplw 9,10; blt 0b"
extern "C" int f_80185820() {}
