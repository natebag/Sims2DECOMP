// 0x80202378 RGTTarget::FindActualRingtoneIndex(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 7,3; mr. 4,4; li 3,0; beqlr; lis 9,-32688; li 3,99; addi 6,9,-13712; li 8,0; li 11,1; li 10,4; b 1f; 0:; addi 10,10,4; addi 11,11,1; 1:; cmpwi 11,9; bgtlr; lwz 0,0x8c(7); mulli 0,0,40; add 0,10,0; lwzx 9,6,0; cmpwi 9,0; beq 2f; addi 8,8,1; 2:; cmpw 8,4; bne 0b; mr 3,11"
extern "C" int f_80202378() {}
