// 0x8019CF0C CASMorphTarget::SetVariableSubnav(UIScreenID, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="mr. 6,6; bnelr; cmpwi 4,6; bne 4f; cmpwi 5,1; beq 2f; bgt 0f; cmpwi 5,0; beq 1f; blr; 0:; cmpwi 5,2; beq 3f; blr; 1:; stw 6,0x8c(3); blr; 2:; stw 5,0x8c(3); blr; 3:; li 0,3; stw 0,0x8c(3); blr; 4:; cmpwi 4,8; bnelr; cmpwi 5,2; beq 9f; bgt 5f; cmpwi 5,0; beq 6f; cmpwi 5,1; beq 8f; blr; 5:; cmpwi 5,4; beq 11f; blt 10f; blr; 6:; li 0,2; 7:; stw 6,0x98(3); stw 0,0x8c(3); blr; 8:; li 0,4; b 7b; 9:; li 0,6; b 7b; 10:; li 0,5; b 7b; 11:; li 0,7; b 7b"
extern "C" void f_8019CF0C() {}
