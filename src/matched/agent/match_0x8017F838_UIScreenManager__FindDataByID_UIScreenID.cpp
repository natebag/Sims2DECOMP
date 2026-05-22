// 0x8017F838 UIScreenManager::FindDataByID(UIScreenID) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 3,0; addi 9,9,18208; li 11,0; mr 10,9; 0:; lwzx 0,11,9; cmpw 0,4; bne 1f; mr 3,10; 1:; addi 10,10,24; addi 11,11,24; cmpwi 3,0; bnelr; lwzx 0,11,9; cmpwi 0,69; bne 0b"
extern "C" int f_8017F838() {}
