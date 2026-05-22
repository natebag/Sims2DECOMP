// 0x801DCE90 GetRecipeName(RCPTarget::Recipe (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; beq 0f; lwz 9,0x10(3); cmpwi 9,0; bne 1f; 0:; li 3,0; blr; 1:; lwz 3,0x4(3); li 0,0; cmpwi 3,3; beq 6f; bgt 2f; cmpwi 3,1; beq 4f; bgt 5f; cmpwi 3,0; beq 3f; b 12f; 2:; cmpwi 3,5; beq 8f; blt 7f; cmpwi 3,6; beq 9f; b 12f; 3:; lwz 9,0x24(9); b 10f; 4:; lwz 9,0x28(9); b 10f; 5:; lwz 9,0x2c(9); b 10f; 6:; lwz 9,0x30(9); b 10f; 7:; lwz 9,0x34(9); b 10f; 8:; lwz 9,0x38(9); b 10f; 9:; lwz 9,0x3c(9); 10:; li 3,0; cmpwi 9,0; beq 11f; lwz 3,0x0(9); 11:; mr 0,3; 12:; mr 3,0"
extern "C" int f_801DCE90() {}
