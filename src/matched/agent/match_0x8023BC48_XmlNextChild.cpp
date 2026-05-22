// 0x8023BC48 XmlNextChild (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; 0:; lbzu 0,0x1(9); cmpwi 0,0; beq 1f; cmpwi 0,47; beq 2f; cmpwi 0,60; bne 0b; 1:; lbz 0,0x0(9); cmpwi 0,47; bne 3f; 2:; li 3,0; blr; 3:; cmpwi 0,60; bne 4f; lbz 0,0x1(9); li 3,0; cmpwi 0,47; beqlr; 4:; mr 3,9"
extern "C" int f_8023BC48() {}
