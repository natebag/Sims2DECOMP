// 0x800BCB04 IconGroupImpl::GetSpriteID(int) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0xc(9); cmpwi 3,0; beq 0f; lhz 3,0x4(3); extsh 0,3; cmpwi 0,-1; beq 0f; add 3,3,4; extsh 3,3; blr; 0:; lwz 0,0x4(9); cmpwi 0,0; bne 1f; cmpwi 4,0; blt 1f; cmpwi 4,18; bgt 1f; lis 9,-32706; add 0,4,4; addi 9,9,-25026; lhax 3,9,0; blr; 1:; li 3,0"
extern "C" int f_800BCB04() {}
