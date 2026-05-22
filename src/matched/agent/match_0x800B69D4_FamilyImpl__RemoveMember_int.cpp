// 0x800B69D4 FamilyImpl::RemoveMember(int) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 11,3,36; lwz 9,0x24(3); lwz 0,0x4(11); cmpw 9,0; beqlr; 0:; lwz 0,0x0(9); cmpw 0,4; bne 3f; addi 3,3,36; addi 0,9,4; lwz 8,0x4(3); cmpw 0,8; beq 2f; mr 11,0; mr 10,9; subf 0,11,8; srawi. 9,0,2; ble 2f; 1:; lwz 0,0x0(11); addic. 9,9,-1; addi 11,11,4; stw 0,0x0(10); addi 10,10,4; bgt 1b; 2:; lwz 9,0x4(3); addi 9,9,-4; stw 9,0x4(3); blr; 3:; lwz 0,0x4(11); addi 9,9,4; cmpw 9,0; bne 0b"
extern "C" void f_800B69D4() {}
