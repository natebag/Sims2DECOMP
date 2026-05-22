// 0x802AB380 AptRenderingContext::getVertexMatrix(AptMatrix (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x3bc(3); cmpwi 0,0; ble 0f; addi 9,3,32; lwz 0,0x20(3); lwz 11,0x4(9); lwz 10,0x8(9); lwz 8,0xc(9); stw 0,0x0(4); stw 11,0x4(4); stw 10,0x8(4); stw 8,0xc(4); lwz 0,0x14(9); lwz 11,0x10(9); stw 0,0x14(4); stw 11,0x10(4); blr; 0:; lis 9,-32694; lwz 0,-11388(9); addi 11,9,-11388; lwz 9,0x8(11); lwz 10,0x4(11); lwz 8,0xc(11); stw 0,0x0(4); stw 10,0x4(4); stw 9,0x8(4); stw 8,0xc(4); lwz 0,0x14(11); lwz 9,0x10(11); stw 0,0x14(4); stw 9,0x10(4)"
extern "C" void f_802AB380() {}
