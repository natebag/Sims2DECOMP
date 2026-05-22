// 0x802443FC vfprintf (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,4; mr 6,5; lbz 0,0x0(11); mr 4,3; mr 9,11; cmpwi 0,0; beq 7f; 0:; lbz 0,0x0(9); cmpwi 0,37; bne 6f; lbz 0,0x1(9); cmpwi 0,0; beq 6f; lbzu 0,0x1(9); lwz 3,0x5c(4); b 2f; 1:; lbzu 0,0x1(9); 2:; extsb 0,0; cmpwi 0,64; bgt 3f; lbz 0,0x1(9); cmpwi 0,0; bne 1b; 3:; lbz 0,0x0(9); extsb 0,0; cmpwi 0,76; beq 5f; bgt 4f; cmpwi 0,69; beq 5f; cmpwi 0,71; beq 5f; b 6f; 4:; cmpwi 0,103; bgt 6f; cmpwi 0,101; blt 6f; 5:; mr 5,11; bl _s802443FC_0; b 8f; 6:; lbzu 0,0x1(9); cmpwi 0,0; bne 0b; 7:; lwz 3,0x5c(4); mr 5,11; crxor 6,6,6; bl _s802443FC_1; 8:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802443FC_0();
extern "C" void _s802443FC_1();
extern "C" void f_802443FC() {}
