// 0x8019A5F4 CASSelectionTarget::UpdateSelectionArrowState(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x544(3); cmpwi 0,1; bne 0f; lis 4,-32705; lis 8,-32705; lwz 3,-25136(13); addi 4,4,-14252; addi 8,8,-15592; b 2f; 0:; lwz 3,0x548(3); cmpwi 3,1; bne 1f; lis 4,-32705; lis 8,-32705; lwz 3,-25136(13); addi 4,4,-14252; addi 8,8,-14228; b 2f; 1:; cmpw 3,0; bne 3f; lis 4,-32705; lis 8,-32705; lwz 3,-25136(13); addi 4,4,-14252; addi 8,8,-15588; 2:; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8019A5F4_0; b 4f; 3:; lis 4,-32705; lis 8,-32705; lwz 3,-25136(13); addi 4,4,-14252; addi 8,8,-14224; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8019A5F4_1; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8019A5F4_0();
extern "C" void _s8019A5F4_1();
extern "C" void f_8019A5F4() {}
