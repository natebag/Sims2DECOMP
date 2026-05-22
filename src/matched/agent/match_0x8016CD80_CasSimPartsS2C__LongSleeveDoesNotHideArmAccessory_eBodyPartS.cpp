// 0x8016CD80 CasSimPartsS2C::LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="cmpwi 4,11; beq 0f; cmpwi 4,14; beq 3f; b 2f; 0:; lwz 11,0x4(3); mulli 10,5,104; li 3,1; lwz 9,0xc(11); add 9,9,10; lbz 0,0x30(9); 1:; cmpwi 0,0; bnelr; 2:; li 3,0; blr; 3:; lwz 11,0x4(3); mulli 10,5,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x1e(9); b 1b"
extern "C" void f_8016CD80() {}
