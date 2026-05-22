// 0x8024AA14 eh_context_static (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; lwz 0,-24928(9); cmpwi 0,0; bne 0f; lis 30,-32694; li 0,1; addi 30,30,-24944; stw 0,-24928(9); mr 3,30; li 4,0; li 5,16; crxor 6,6,6; bl _s8024AA14_0; lis 9,-32694; addi 9,9,-24924; stw 9,0x4(30); 0:; lis 3,-32694; addi 3,3,-24944; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8024AA14_0();
extern "C" void f_8024AA14() {}
