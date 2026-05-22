// 0x8039FE24 _Rb_global<bool>::_M_decrement(_Rb_tree_node_base (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); cmpwi 0,0; bne 0f; lwz 9,0x4(3); lwz 0,0x4(9); cmpw 0,3; bne 0f; lwz 3,0xc(3); blr; 0:; lwz 0,0x8(3); cmpwi 0,0; beq 3f; mr 3,0; lwz 0,0xc(3); cmpwi 0,0; beqlr; 1:; lwz 3,0xc(3); lwz 0,0xc(3); cmpwi 0,0; bne 1b; blr; 2:; mr 3,9; 3:; lwz 9,0x4(3); lwz 0,0x8(9); cmpw 3,0; beq 2b; mr 3,9"
extern "C" int f_8039FE24() {}
