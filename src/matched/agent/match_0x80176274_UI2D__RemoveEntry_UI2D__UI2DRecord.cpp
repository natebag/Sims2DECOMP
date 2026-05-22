// 0x80176274 UI2D::RemoveEntry(UI2D::UI2DRecord (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lwz 9,0x0(31); cmpwi 9,0; beq 0f; lwz 0,0x4(31); stw 0,0x4(9); 0:; lwz 9,0x4(31); cmpwi 9,0; beq 1f; lwz 0,0x0(31); stw 0,0x0(9); 1:; lwz 0,0x0(30); cmpw 0,31; bne 2f; lwz 0,0x4(31); stw 0,0x0(30); 2:; lwz 0,0x4(30); cmpw 0,31; bne 3f; lwz 0,0x0(31); stw 0,0x4(30); 3:; li 0,0; stw 0,0x4(31); stw 0,0x0(31); lwz 0,0x8(30); cmpwi 0,0; beq 4f; stw 0,0x4(31); lwz 9,0x8(30); stw 31,0x0(9); 4:; stw 31,0x8(30); lwz 4,0x24(31); cmpwi 4,0; beq 5f; lis 3,-32692; li 5,1; addi 3,3,-17444; bl _s80176274_0; 5:; lwz 0,0x1c(31); cmpwi 0,0; beq 6f; lwz 9,0x8(30); lis 3,-32692; addi 3,3,-17444; lwz 4,0xc(9); bl _s80176274_1; b 7f; 6:; lwz 9,0x8(30); lwz 3,0x18(9); cmpwi 3,0; beq 7f; bl _s80176274_2; 7:; lwz 11,0x8(30); li 0,0; stw 0,0x8(11); lwz 9,0x8(30); stw 0,0xc(9); lwz 11,0x8(30); stw 0,0x10(11); lwz 9,0x8(30); stw 0,0x14(9); lwz 11,0x8(30); stw 0,0x18(11); lwz 9,0x8(30); stw 0,0x1c(9); lwz 11,0x8(30); stw 0,0x20(11); lwz 9,0x8(30); stw 0,0x24(9); lwz 11,0x8(30); stw 0,0x28(11); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80176274_0();
extern "C" void _s80176274_1();
extern "C" void _s80176274_2();
extern "C" void f_80176274() {}
