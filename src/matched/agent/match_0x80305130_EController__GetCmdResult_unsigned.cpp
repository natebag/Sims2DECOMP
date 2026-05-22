// 0x80305130 EController::GetCmdResult(unsigned (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 30,3; mr 31,4; mr 28,5; mr 29,6; cmpwi 4,7,0; beq cr4,0f; lwz 9,0x200(30); li 3,0; lwz 0,0x78(9); cmpwi 0,0; bne 5f; 0:; mr 3,30; mr 4,31; bl _s80305130_0; mr. 3,3; beq 4f; lwz 0,0x0(3); cmpw 0,31; bne 4f; mcrf cr7,cr4; li 11,1; 1:; lwz 9,0x4(3); and. 0,28,9; beq 3f; and 0,29,9; cmpw 0,9; bne 3f; beq cr7,2f; lwz 9,0x200(30); stw 11,0x78(9); 2:; li 3,1; b 5f; 3:; addic. 3,3,8; beq 4f; lwz 0,0x0(3); cmpw 0,31; beq 1b; 4:; li 3,0; 5:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80305130_0();
extern "C" void f_80305130() {}
