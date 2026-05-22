// 0x8031BC10 ERQuickdata::getStartAddr(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 0,4,20; lwz 11,0x14(3); addi 9,11,28; lwzx 3,9,0; cmpwi 3,0; bnelr; mr 0,4; cmpwi 0,0; addi 4,4,-1; blelr; mulli 9,4,20; addi 9,9,36; add 9,9,11; 0:; lwz 3,-8(9); cmpwi 3,0; beq 2f; lwz 11,0x4(9); cmpwi 11,0; bne 1f; li 11,1; 1:; lwz 0,0x0(9); mullw 0,11,0; add 3,3,0; blr; 2:; mr 0,4; addi 9,9,-20; cmpwi 0,0; addi 4,4,-1; bgt 0b"
extern "C" int f_8031BC10() {}
