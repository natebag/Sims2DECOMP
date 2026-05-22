// 0x8017FE64 UIScreenManager::AddScreen(UIScreenID, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,24; addi 3,3,132; mtspr 9,0; li 11,0; li 9,0; 0:; lwz 0,0x4(3); cmpwi 0,0; bne 1f; mr 9,3; 1:; addi 3,3,16; cmpwi 9,0; bne 2f; bdnz 0b; b 3f; 2:; li 0,1; stw 4,0x0(9); stw 0,0x4(9); li 11,1; stw 5,0xc(9); 3:; mr 3,11"
extern "C" void f_8017FE64() {}
