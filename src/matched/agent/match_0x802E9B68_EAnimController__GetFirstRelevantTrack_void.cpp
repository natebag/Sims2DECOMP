// 0x802E9B68 EAnimController::GetFirstRelevantTrack(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x8(3); cmpwi 10,-1; beq 1f; mulli 9,10,176; lwz 11,0x44(3); li 8,1; add 9,9,11; lwz 0,0x7c(9); cmpwi 0,0; bne 0f; li 8,0; 0:; cmpwi 8,0; beq 1f; mr 3,10; blr; 1:; lwz 0,0x6c(3); li 11,0; cmplw 11,0; bge 5f; lwz 7,0x44(3); mr 8,0; lwz 10,0x70(3); 2:; lbzx 0,10,11; extsb 3,0; mulli 9,3,176; add 9,7,9; lwz 0,0xa8(9); cmpwi 0,0; beq 4f; lwz 0,0x7c(9); li 9,1; cmpwi 0,0; bne 3f; li 9,0; 3:; cmpwi 9,0; bnelr; 4:; addi 11,11,1; cmplw 11,8; blt 2b; 5:; li 3,-1"
extern "C" int f_802E9B68() {}
