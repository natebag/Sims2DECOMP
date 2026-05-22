// 0x80298F64 AptPseudoData_t::AptPseudoData_t(AptControl (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sth 5,0x18(3); addi 11,4,4; lwz 0,0x4(4); stw 6,0x0(3); stw 0,0x14(3); lhz 9,0x3a(4); sth 9,0x1a(3); lwz 0,0x4(4); andi. 0,0,4; beq 0f; addi 0,4,16; 0:; stw 0,0x4(3); lwz 0,0x0(11); li 9,0; andi. 10,0,8; beq 1f; addi 9,11,36; 1:; stw 9,0x8(3); li 9,0; lwz 0,0x0(11); andi. 10,0,128; beq 2f; lwz 9,0x38(11); 2:; stw 9,0xc(3); lwz 0,0x0(11); andi. 9,0,16; beq 3f; lfs f0,0x2c(11); b 4f; 3:; lis 9,-32704; lfs f0,0x73f8(9); 4:; stfs f0,0x10(3)"
extern "C" void f_80298F64() {}
