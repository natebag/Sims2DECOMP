// 0x800E178C cXObjectImpl::GetTileWidth(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,2; bne 3f; cmpwi 31,0; beq 0f; lwz 9,0x4(31); li 4,2; lwz 3,0x0(9); bl _s800E178C_0; mr 11,3; b 1f; 0:; li 11,0; 1:; cmpwi 11,0; beq 2f; lwz 9,0x4(11); lha 3,0x218(9); lwz 0,0x21c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; li 3,0; b 4f; 2:; bl _s800E178C_1; b 4f; 3:; lwz 9,0x88(31); lha 0,0x86(9); mr 3,0; cmpwi 0,0; bne 4f; li 3,16; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800E178C_0();
extern "C" void _s800E178C_1();
extern "C" void f_800E178C() {}
