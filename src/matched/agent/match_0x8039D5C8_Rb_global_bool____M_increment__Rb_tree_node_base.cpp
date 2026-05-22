// 0x8039D5C8 _Rb_global<bool>::_M_increment(_Rb_tree_node_base (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); cmpwi 0,0; beq 2f; mr 3,0; lwz 0,0x8(3); cmpwi 0,0; beqlr; 0:; lwz 3,0x8(3); lwz 0,0x8(3); cmpwi 0,0; bne 0b; blr; 1:; mr 3,9; 2:; lwz 9,0x4(3); lwz 0,0xc(9); cmpw 3,0; beq 1b; lwz 0,0xc(3); cmpw 0,9; beqlr; mr 3,9"
extern "C" int f_8039D5C8() {}
