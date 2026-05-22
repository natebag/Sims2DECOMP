// 0x800D4558 NghResFile::IsSectionLoaded(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 11,0; cmpwi 4,1; beq 4f; cmplwi 4,1; blt 0f; cmpwi 4,2; beq 5f; cmpwi 4,3; beq 7f; b 8f; 0:; lwz 9,0x138(3); lwz 0,0x8(9); cmpwi 0,0; bne 2f; li 0,16; mtspr 9,0; 1:; bdnz 1b; li 11,0; b 8f; 2:; li 0,16; mtspr 9,0; 3:; bdnz 3b; li 11,1; b 8f; 4:; lwz 9,0x138(3); li 11,1; lwz 0,0x0(9); b 6f; 5:; lwz 9,0x17c(3); li 11,1; lwz 0,0x4(9); 6:; cmpwi 0,0; bne 8f; li 11,0; b 8f; 7:; lwz 4,0x24(3); addi 4,4,1; bl _s800D4558_0; mr 11,3; 8:; mr 3,11; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800D4558_0();
extern "C" void f_800D4558() {}
