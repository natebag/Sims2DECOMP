// 0x80164DEC CasNpcEditor::SaveCostume(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x8(31); cmpwi 0,3; bne 0f; lwz 0,0x10(31); cmplwi 0,161; ble 1f; 0:; li 3,0; b 7f; 1:; lwz 3,0x0(31); bl _s80164DEC_0; mr. 6,3; beq 5f; lwz 0,0x10(31); mr 5,0; subfic 4,5,80; li 4,0; adde. 4,4,4; bne 2f; addi 5,5,-81; 2:; lis 30,-32697; addi 30,30,24012; lwz 3,0x490(30); bl _s80164DEC_1; mr 31,3; lwz 3,0x490(30); bl _s80164DEC_2; cmpwi 31,0; li 0,1; bne 3f; li 0,0; 3:; cmpwi 3,0; li 3,1; bne 4f; li 3,0; 4:; and 31,0,3; b 6f; 5:; li 31,0; 6:; mr 3,31; 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80164DEC_0();
extern "C" void _s80164DEC_1();
extern "C" void _s80164DEC_2();
extern "C" void f_80164DEC() {}
