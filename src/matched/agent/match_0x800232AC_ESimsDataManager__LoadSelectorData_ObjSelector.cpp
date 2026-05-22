// 0x800232AC ESimsDataManager::LoadSelectorData(ObjSelector (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,1; mr 30,4; stw 0,0x9c(30); mr 31,3; mr 29,5; lwz 0,0xd20(31); cmpwi 0,0; bne 0f; lwz 0,0xa0(30); cmpwi 0,1; beq 1f; 0:; mr 3,31; bl _s800232AC_0; lwz 10,-22652(13); li 0,2; stw 0,0xd20(31); lis 6,-32697; mr 4,31; addi 6,6,18080; lwz 11,0x0(10); mr 8,30; mr 9,29; li 5,1; lha 3,0x50(11); li 7,0; lwz 0,0x54(11); add 3,10,3; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800232AC_0();
extern "C" void f_800232AC() {}
