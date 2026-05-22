// 0x800FBBE0 _Rb_global<bool>::_M_increment(_Rb_tree_node_base (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800FBC40" lines="addi 0,31,-15; cmplwi 0,3; b 0f; addi 0,31,-70; cmplwi 0,1; 0:; bgt 2f; li 0,13; stw 0,0x48(28); b 2f; cmpwi 31,19; bgt 1f; li 0,16; stw 0,0x48(28); b 2f; 1:; li 0,2; li 9,13; stw 0,0x44(28); stw 9,0x48(28); 2:; lis 9,-32706; lfs f0,-16652(9); stfs f0,0x5c(28)"
extern "C" void f_800FBC40();
extern "C" void f_800FBBE0() {}
