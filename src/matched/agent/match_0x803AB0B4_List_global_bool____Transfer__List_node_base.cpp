// 0x803AB0B4 _List_global<bool>::_Transfer(_List_node_base (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpw 3,5; beqlr; lwz 9,0x4(5); stw 3,0x0(9); lwz 11,0x4(4); stw 5,0x0(11); lwz 9,0x4(3); stw 4,0x0(9); lwz 11,0x4(5); lwz 9,0x4(3); stw 11,0x4(3); lwz 0,0x4(4); stw 0,0x4(5); stw 9,0x4(4)"
extern "C" void f_803AB0B4() {}
