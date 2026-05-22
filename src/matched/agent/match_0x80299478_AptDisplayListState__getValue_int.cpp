// 0x80299478 AptDisplayListState::getValue(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); cmpwi 3,0; beq 1f; 0:; cmpwi 4,0; beqlr; lwz 3,0x54(3); addi 4,4,-1; cmpwi 3,0; bne 0b; 1:; li 3,0"
extern "C" int f_80299478() {}
