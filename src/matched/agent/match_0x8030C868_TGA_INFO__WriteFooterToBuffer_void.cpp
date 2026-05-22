// 0x8030C868 TGA_INFO::WriteFooterToBuffer(void (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); stmw 30,0x28(1); lis 9,-32702; addi 11,1,8; lwz 0,-757(9); li 3,26; addi 9,9,-757; lhz 10,0x18(9); lwz 8,0x4(9); lwz 7,0x8(9); lwz 6,0xc(9); lwz 5,0x10(9); lwz 30,0x14(9); stw 0,0x8(1); sth 10,0x18(11); stw 8,0x4(11); stw 7,0x8(11); stw 6,0xc(11); stw 5,0x10(11); stw 30,0x14(11); sth 10,0x18(4); lwz 0,0x8(1); stw 8,0x4(4); stw 0,0x0(4); stw 7,0x8(4); stw 6,0xc(4); stw 5,0x10(4); stw 30,0x14(4); lmw 30,0x28(1); addi 1,1,48"
extern "C" void f_8030C868() {}
