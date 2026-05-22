// 0x80054CA0 EIObjectMan::GetObjectsInRect(int, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,5; cmpwi 4,0; li 30,8; bne 0f; li 30,1; 0:; lwz 31,0x4(3); cmpwi 31,0; beq 3f; 1:; lwz 4,0x1c(31); lwz 0,0x32c(4); and. 9,0,30; beq 2f; mr 3,29; bl _s80054CA0_0; 2:; lwz 31,0x10(31); cmpwi 31,0; bne 1b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80054CA0_0();
extern "C" void f_80054CA0() {}
