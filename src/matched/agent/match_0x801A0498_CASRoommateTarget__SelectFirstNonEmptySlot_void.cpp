// 0x801A0498 CASRoommateTarget::SelectFirstNonEmptySlot(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,4; lwz 11,0x90(3); mtspr 9,0; li 8,0; li 10,0; 0:; add 11,11,10; mr 0,11; cmpwi 11,0; bge 1f; addi 0,11,3; 1:; rlwinm 0,0,0,0,29; lwz 9,0x84(3); subf 11,0,11; lwz 9,0x1c(9); mr 0,11; cmpwi 11,0; bge 2f; addi 0,11,3; 2:; lwz 9,0x1348(9); rlwinm 0,0,0,0,29; subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 3f; li 8,1; b 4f; 3:; addi 10,10,1; bdnz 0b; 4:; stw 11,0x90(3); mr 3,8"
extern "C" void f_801A0498() {}
