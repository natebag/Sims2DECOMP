// 0x8016CE80 CasSimPartsS2C::OuterLayerTorsoIsAHood(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="mr. 5,5; beq 0f; cmpwi 5,1; beq 3f; b 2f; 0:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x60(9); 1:; cmpwi 0,0; bnelr; 2:; li 3,0; blr; 3:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x61(9); b 1b"
extern "C" void f_8016CE80() {}
