// 0x802AA400 AptNativeHash::GetFirstItem(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); cmpwi 0,0; bne 0f; li 3,0; blr; 0:; lwz 3,0x0(3); li 10,0; cmpw 10,3; bge 4f; lis 9,-32700; mr 8,3; addi 9,9,-6476; mr 3,0; 1:; lwz 0,0x0(3); li 11,1; cmpwi 0,0; bne 2f; li 11,0; 2:; cmpwi 11,0; beq 3f; cmpw 0,9; bnelr; 3:; addi 10,10,1; addi 3,3,8; cmpw 10,8; blt 1b; 4:; li 3,0"
extern "C" int f_802AA400() {}
