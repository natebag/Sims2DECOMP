// 0x800F8214 ObjectModuleImpl::CleanupPeople(cXObject (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); addi 9,3,8280; lwz 31,0x2058(3); lwz 0,0x4(9); mr 30,4; cmpw 31,0; beq 4f; mr 29,9; cmpwi 4,30,0; 0:; lwz 0,0x0(31); mr 11,0; cmpwi 0,0; beq 1f; lwz 9,0x4(11); lwz 0,0x0(9); cmpw 0,30; bne 2f; b 3f; 1:; beq cr4,3f; 2:; lwz 3,0x4(11); mr 4,30; lwz 9,0x4(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; 3:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 4:; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void f_800F8214() {}
