// 0x800ECE08 ObjectFolderImpl::GetLeadSelector(ObjSelector (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 30,3; lwz 9,0x38(29); lha 28,0x14(9); cmpwi 28,0; bne 1f; li 3,0; b 4f; 0:; mr 3,31; b 4f; 1:; li 31,0; b 3f; 2:; mr 3,31; mr 4,29; bl _s800ECE08_0; cmpwi 3,0; beq 3f; lwz 9,0x38(31); lha 0,0x14(9); cmpw 0,28; bne 3f; lha 0,0x7e(9); cmpwi 0,0; bne 0b; 3:; lwz 9,0x0(30); mr 4,31; lha 3,0x70(9); lwz 0,0x74(9); add 3,30,3; mtspr 8,0; blrl; mr. 31,3; bne 2b; lwz 9,0x0(30); mr 4,29; li 5,0; li 6,0; lha 3,0x90(9); li 7,0; lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800ECE08_0();
extern "C" void f_800ECE08() {}
