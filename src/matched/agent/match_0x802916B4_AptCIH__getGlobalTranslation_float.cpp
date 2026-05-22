// 0x802916B4 AptCIH::getGlobalTranslation(float (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lis 9,-32694; addi 11,1,8; lwz 30,-11388(9); mr 29,4; addi 9,9,-11388; mr 28,5; lwz 6,0x14(9); mr. 31,3; lwz 7,0x4(9); lwz 8,0x8(9); lwz 0,0xc(9); lwz 10,0x10(9); stw 30,0x8(1); stw 6,0x14(11); stw 7,0x4(11); stw 8,0x8(11); stw 0,0xc(11); stw 10,0x10(11); beq 1f; 0:; addi 3,1,8; addi 4,31,16; mr 5,3; bl _s802916B4_0; lwz 31,0x48(31); cmpwi 31,0; bne 0b; 1:; cmpwi 29,0; beq 2f; lfs f0,0x18(1); stfs f0,0x0(29); 2:; cmpwi 28,0; beq 3f; lfs f0,0x1c(1); stfs f0,0x0(28); 3:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802916B4_0();
extern "C" void f_802916B4() {}
