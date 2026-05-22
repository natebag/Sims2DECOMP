// 0x801BBC24 INGTarget::add_mix_ing(INGTarget::IngInfo (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 8,3; mr. 4,4; bne 1f; 0:; li 3,-1; blr; 1:; lwz 0,0x4(4); cmplw 0,5; blt 0b; li 0,4; addi 10,8,484; mtspr 9,0; li 3,0; mr 7,10; addi 9,8,480; li 11,0; 2:; lwzx 0,11,7; cmpwi 0,0; bne 4f; lwz 0,0x0(4); stw 0,0x0(9); stwx 5,11,10; lwz 9,0x0(4); lha 0,0x2(9); cmpwi 0,0; bne 3f; lwz 0,0x4(4); subf 0,5,0; stw 0,0x4(4); 3:; lwz 11,0x0(4); lwz 10,0x454(8); lha 0,0x2(11); lwz 9,0x444(8); mullw 0,0,10; subf 9,0,9; stw 9,0x444(8); blr; 4:; addi 9,9,8; addi 11,11,8; addi 3,3,1; bdnz 2b; li 3,-1"
extern "C" void f_801BBC24() {}
