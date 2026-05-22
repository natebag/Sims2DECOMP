// 0x803C2368 AllocPoolManager<FastAllocPool>::FindPoolForBlock(void (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 0,0x0(9); cmplw 4,0; blt 0f; lwz 0,0x4(9); cmplw 4,0; blt 1f; 0:; li 3,0; blr; 1:; lwz 0,0x8(9); addi 11,9,8; cmplw 4,0; blt 4f; lwz 0,0x68(9); addi 3,9,104; cmplw 4,0; blt 3f; lwz 0,0x98(9); addi 9,9,152; 2:; cmplw 4,0; bltlr; mr 3,9; blr; 3:; lwz 0,0x38(9); mr 3,11; addi 9,9,56; b 2b; 4:; lwz 0,0x80(9); addi 3,9,128; cmplw 4,0; blt 5f; lwz 0,0x20(9); addi 9,9,32; b 2b; 5:; lwz 0,0x50(9); addi 3,9,80; cmplw 4,0; bgelr; addi 3,9,176"
extern "C" int f_803C2368() {}
