// 0x8028AF08 AptCharacterInst::sMethod_play(AptValue (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 29,0; li 30,0; bl _s8028AF08_0; cmpwi 3,13; bne 0f; mr 3,31; bl _s8028AF08_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; mr 3,31; li 30,0; bl _s8028AF08_2; cmpwi 3,18; bne 1f; mr 3,31; bl _s8028AF08_3; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 4f; lwz 9,0x4c(31); lwz 0,0x1c(9); ori 0,0,64; stw 0,0x1c(9); 4:; lwz 3,-22936(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8028AF08_0();
extern "C" void _s8028AF08_1();
extern "C" void _s8028AF08_2();
extern "C" void _s8028AF08_3();
extern "C" void f_8028AF08() {}
