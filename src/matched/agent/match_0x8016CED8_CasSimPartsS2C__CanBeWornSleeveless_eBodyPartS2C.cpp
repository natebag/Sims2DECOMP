// 0x8016CED8 CasSimPartsS2C::CanBeWornSleeveless(eBodyPartS2C, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="cmpwi 4,11; beq 4f; bgt 0f; cmpwi 4,8; beq 1f; b 3f; 0:; cmpwi 4,14; beq 5f; b 3f; 1:; lwz 11,0x4(3); mulli 0,5,68; lbz 10,0x0(6); li 3,1; lwz 9,0x8(11); extsb 10,10; add 9,9,0; lwz 11,0x2c(9); 2:; lbzx 0,11,10; cmpwi 0,0; bnelr; 3:; li 3,0; blr; 4:; lwz 11,0x4(3); mulli 0,5,104; lbz 10,0x0(6); li 3,1; lwz 9,0xc(11); extsb 10,10; add 9,9,0; lwz 11,0x5c(9); b 2b; 5:; lwz 11,0x4(3); mulli 0,5,100; lbz 10,0x0(6); li 3,1; lwz 9,0x10(11); extsb 10,10; add 9,9,0; lwz 11,0x40(9); b 2b"
extern "C" void f_8016CED8() {}
