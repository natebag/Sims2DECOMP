// 0x801BEF40 K2YTarget::SetStartMode(K2YTarget::eK2yboardMode) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-30256(13); cmpwi 0,5; beq 2f; ble 0f; cmpwi 0,8; beq 3f; blt 1f; b 4f; 0:; cmpwi 0,3; beq 4f; bgt 1f; cmpwi 0,0; blt 4f; 1:; stw 3,-30256(13); blr; 2:; li 0,4; stw 0,-30256(13); blr; 3:; li 0,7; stw 0,-30256(13); blr; 4:; li 0,2; stw 0,-30256(13)"
extern "C" void f_801BEF40() {}
