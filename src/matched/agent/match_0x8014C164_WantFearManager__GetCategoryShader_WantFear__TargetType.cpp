// 0x8014C164 WantFearManager::GetCategoryShader(WantFear::TargetType, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 11,0; lwz 0,0x24(9); cmplw 11,0; bge 4f; lwz 3,0x18(3); mr 9,0; 0:; lwz 0,0x0(3); cmpw 0,4; bne 3f; lwz 0,0x4(3); li 9,0; cmpw 9,0; bge 4f; lwz 3,0x8(3); mr 11,0; 1:; lha 0,0x0(3); cmpw 0,5; bne 2f; lwz 0,0x4(3); lis 3,-16260; ori 3,3,13636; cmpwi 0,0; beqlr; mr 3,0; blr; 2:; addi 9,9,1; addi 3,3,8; cmpw 9,11; blt 1b; b 4f; 3:; addi 11,11,1; addi 3,3,12; cmplw 11,9; blt 0b; 4:; lis 3,-16260; ori 3,3,13636"
extern "C" int f_8014C164() {}
