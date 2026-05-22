// 0x80178B24 GetLocalizableCommandTable::ExecuteCommand(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 31,0x0(30); mr 28,5; cmpwi 31,0; beq 5f; li 27,0; 0:; lwz 3,0x8(31); mr 4,29; bl _s80178B24_0; cmpwi 3,0; bne 4f; lwz 0,0x0(30); cmpw 31,0; beq 3f; lwz 0,0x4(30); cmpw 31,0; bne 1f; lwz 0,0x0(31); stw 0,0x4(30); b 2f; 1:; lwz 9,0x4(31); lwz 0,0x0(31); stw 0,0x0(9); 2:; lwz 9,0x0(31); lwz 0,0x4(31); stw 0,0x4(9); stw 27,0x0(31); lwz 0,0x0(30); stw 0,0x4(31); lwz 9,0x0(30); stw 31,0x0(9); stw 31,0x0(30); 3:; lwz 9,0xc(31); mr 4,28; lwz 0,0xc(9); mr 3,9; mtspr 8,0; blrl; b 6f; 4:; lwz 31,0x4(31); cmpwi 31,0; bne 0b; 5:; li 3,0; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80178B24_0();
extern "C" void f_80178B24() {}
