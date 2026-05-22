// 0x802AA470 AptNativeHash::GetNextItem(AptHashItem (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 11,0x4(9); mr 3,4; cmpwi 11,0; bne 0f; li 3,0; blr; 0:; lwz 0,0x0(9); addi 3,3,8; rlwinm 0,0,3,0,28; add 0,11,0; cmplw 3,0; bge 4f; lis 9,-32700; addi 9,9,-6476; 1:; lwz 11,0x0(3); li 10,1; cmpwi 11,0; bne 2f; li 10,0; 2:; cmpwi 10,0; beq 3f; cmpw 11,9; bnelr; 3:; addi 3,3,8; cmplw 3,0; blt 1b; 4:; li 3,0"
extern "C" int f_802AA470() {}
