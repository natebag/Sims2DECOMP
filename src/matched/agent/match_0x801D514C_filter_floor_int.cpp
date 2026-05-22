// 0x801D514C filter_floor(int, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; bne 1f; 0:; li 3,0; blr; 1:; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 2f; li 3,1; blr; 2:; cmpwi 3,0; beq 0b; lwz 0,0xc(5); cmpw 0,4; beq 0b; lbz 0,0x14(5); li 3,1; cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_801D514C() {}
