// 0x8004B5BC get_ingredient_type_array(FoodResult (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; mr. 3,3; sth 0,0x0(4); sth 0,0x6(4); sth 0,0x4(4); sth 0,0x2(4); bne 0f; li 3,0; blr; 0:; lwz 9,0x4(3); cmpwi 9,0; beq 1f; lhz 0,0x0(9); sth 0,0x0(4); 1:; lwz 9,0x8(3); cmpwi 9,0; beq 2f; lhz 0,0x0(9); sth 0,0x2(4); 2:; lwz 9,0xc(3); cmpwi 9,0; beq 3f; lhz 0,0x0(9); sth 0,0x4(4); 3:; lwz 3,0x10(3); cmpwi 3,0; beq 4f; lhz 0,0x0(3); sth 0,0x6(4); 4:; li 3,1"
extern "C" void f_8004B5BC() {}
