// 0x80087988 _Rb_global<bool>::_M_increment(_Rb_tree_node_base (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x7324(9); li 0,0; lis 9,-32707; stw 0,0x18(31); lfs f0,0x7328(9); mr 3,31; stfs f13,0x1c(31); stfs f13,0x4(10); stfs f0,0x24(31); stfs f0,0x4(8); stfs f0,0x30(31); stw 0,0x3c(31); stfs f0,0x2c(31); stw 0,0x34(31); stw 0,0x38(31); bl _s80087988_0; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80087988_0();
extern "C" void f_80087988() {}
