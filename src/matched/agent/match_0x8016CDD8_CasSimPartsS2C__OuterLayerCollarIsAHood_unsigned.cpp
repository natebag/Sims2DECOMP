// 0x8016CDD8 CasSimPartsS2C::OuterLayerCollarIsAHood(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="cmpwi 5,1; beq 4f; bgt 0f; cmpwi 5,0; beq 1f; b 3f; 0:; cmpwi 5,2; beq 5f; cmpwi 5,3; beq 6f; b 3f; 1:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x54(9); 2:; cmpwi 0,0; bnelr; 3:; li 3,0; blr; 4:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x55(9); b 2b; 5:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x56(9); b 2b; 6:; lwz 11,0x4(3); mulli 10,4,100; li 3,1; lwz 9,0x10(11); add 9,9,10; lbz 0,0x57(9); b 2b"
extern "C" void f_8016CDD8() {}
