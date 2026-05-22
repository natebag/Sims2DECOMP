// 0x800F9310 ObjectModuleImpl::IsValidObject(cXObject (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x0(3); mr 31,4; lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; b 2f; 0:; cmpw 11,31; bne 1f; li 3,1; b 3f; 1:; lwz 9,0x4(11); lha 3,0x490(9); lwz 0,0x494(9); add 3,11,3; mtspr 8,0; 2:; blrl; mr. 11,3; bne 0b; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800F9310() {}
