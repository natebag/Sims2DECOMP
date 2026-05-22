// 0x802036F8 SKNTarget::SetupSkinUnlocks(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x90(3); li 0,1; lis 9,-32688; cmpwi 0,0; mulli 11,11,76; addi 9,9,-13632; li 10,1; li 0,18; mr 6,9; mtspr 9,0; li 7,1; stwx 10,9,11; li 8,4; stw 10,0x8c(3); 0:; lwz 0,0x90(3); mulli 0,0,76; add 0,8,0; addi 8,8,4; stwx 7,6,0; beq 1f; lwz 9,0x8c(3); addi 9,9,1; stw 9,0x8c(3); 1:; bdnz 0b"
extern "C" void f_802036F8() {}
