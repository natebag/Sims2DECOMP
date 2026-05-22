// 0x803C2214 AllocPoolManager<ProtectedAllocPool>::FindPoolForBlock(void (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 0,0x0(9); cmplw 4,0; blt 0f; lwz 0,0x4(9); cmplw 4,0; blt 1f; 0:; li 3,0; blr; 1:; lwz 0,0x8(9); addi 11,9,8; cmplw 4,0; blt 4f; lwz 0,0xd8(9); addi 3,9,216; cmplw 4,0; blt 3f; lwz 0,0x140(9); addi 9,9,320; 2:; cmplw 4,0; bltlr; mr 3,9; blr; 3:; lwz 0,0x70(9); mr 3,11; addi 9,9,112; b 2b; 4:; lwz 0,0x10c(9); addi 3,9,268; cmplw 4,0; blt 5f; lwz 0,0x3c(9); addi 9,9,60; b 2b; 5:; lwz 0,0xa4(9); addi 3,9,164; cmplw 4,0; bgelr; addi 3,9,372"
extern "C" int f_803C2214() {}
