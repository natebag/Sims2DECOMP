// 0x802881B8 AptCharacterSpriteInstBase::AptCharacterSpriteInstBase(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; li 29,-1; lis 9,-32704; addi 9,9,20176; stw 30,0x10(31); stw 29,0x0(31); addi 3,31,36; stw 30,0x8(31); stw 30,0xc(31); stw 9,0x14(31); bl _s802881B8_0; lwz 0,0x1c(31); li 4,20; stw 30,0x20(31); rlwinm 0,0,0,25,23; stw 30,0x28(31); ori 0,0,64; lwz 3,-23020(13); rlwimi 0,30,4,26,27; rlwimi 0,30,8,0,23; stw 0,0x1c(31); bl _s802881B8_1; li 4,8; bl _s802881B8_2; lwz 9,-26996(13); lis 4,-32694; stw 3,0xc(31); addi 4,4,-11332; stw 29,0x18(31); addi 4,4,376; stw 30,0x2c(31); addi 3,9,12; bl _s802881B8_3; lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 30,0xc(3); lwz 29,0xc(31); cmpwi 30,0; beq 0f; lwz 9,0x8(30); lis 4,-32704; lis 5,-32704; addi 4,4,16788; lha 3,0x8(9); addi 5,5,16836; lwz 0,0xc(9); li 6,80; add 3,30,3; mtspr 8,0; blrl; 0:; lwz 11,0x8(29); cmpwi 11,0; beq 1f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,16788; lha 3,0x10(9); addi 5,5,16836; lwz 0,0x14(9); li 6,81; add 3,11,3; mtspr 8,0; blrl; 1:; stw 30,0x8(29); mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802881B8_0();
extern "C" void _s802881B8_1();
extern "C" void _s802881B8_2();
extern "C" void _s802881B8_3();
extern "C" void f_802881B8() {}
