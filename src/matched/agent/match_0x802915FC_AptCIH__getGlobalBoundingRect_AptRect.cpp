// 0x802915FC AptCIH::getGlobalBoundingRect(AptRect (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32694; mr 30,3; lwz 5,-11388(9); addi 11,1,8; addi 9,9,-11388; lwz 31,0x48(30); lwz 6,0x14(9); mr 29,4; lwz 8,0x4(9); cmpwi 31,0; lwz 7,0x8(9); lwz 0,0xc(9); lwz 10,0x10(9); stw 5,0x8(1); stw 6,0x14(11); stw 8,0x4(11); stw 7,0x8(11); stw 0,0xc(11); stw 10,0x10(11); beq 1f; 0:; addi 3,1,8; addi 4,31,16; mr 5,3; bl _s802915FC_0; lwz 31,0x48(31); cmpwi 31,0; bne 0b; 1:; lwz 3,-22920(13); bl _s802915FC_1; lwz 3,-22920(13); addi 4,1,8; bl _s802915FC_2; mr 3,30; mr 4,29; bl _s802915FC_3; lwz 3,-22920(13); bl _s802915FC_4; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s802915FC_0();
extern "C" void _s802915FC_1();
extern "C" void _s802915FC_2();
extern "C" void _s802915FC_3();
extern "C" void _s802915FC_4();
extern "C" void f_802915FC() {}
