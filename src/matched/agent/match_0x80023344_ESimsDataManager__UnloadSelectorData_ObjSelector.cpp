// 0x80023344 ESimsDataManager::UnloadSelectorData(ObjSelector (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; mr 31,4; stw 0,0x9c(31); mr 30,3; lwz 0,0xd20(30); cmpwi 0,0; bne 0f; lwz 0,0xa0(31); cmpwi 0,0; beq 2f; 0:; lwz 0,0xd30(30); cmpw 0,31; bne 1f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; 1:; mr 3,30; mr 4,31; bl _s80023344_0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80023344_0();
extern "C" void f_80023344() {}
