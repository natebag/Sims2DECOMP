// 0x802023E0 RGTTarget::SetupRingtoneUnlocks(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x8c(3); li 0,1; lis 9,-32688; cmpwi 0,0; mulli 11,11,40; addi 9,9,-13712; li 10,1; li 0,9; mr 6,9; mtspr 9,0; li 7,1; stwx 10,9,11; li 8,4; stw 10,0x84(3); 0:; lwz 0,0x8c(3); mulli 0,0,40; add 0,8,0; addi 8,8,4; stwx 7,6,0; beq 1f; lwz 9,0x84(3); addi 9,9,1; stw 9,0x84(3); 1:; bdnz 0b"
extern "C" void f_802023E0() {}
