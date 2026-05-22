// 0x8003FE38 EGlobal::GetWantFearCategoryString(int, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lis 9,-32707; lwz 3,0xe8(4); mr 29,5; mr 31,6; addi 4,9,10212; bl _s8003FE38_0; b 1f; 0:; lwz 0,0x4(9); b 8f; 1:; cmpwi 3,0; beq 7f; lwz 11,0xc(3); li 9,0; lwz 0,0x4(3); cmpw 9,11; bge 7f; mr 3,0; 2:; lwz 0,0x0(3); cmpw 0,29; bne 6f; lwz 3,0x4(3); li 11,0; cmpwi 7,3,0; mr 9,3; b 4f; 3:; lhz 0,0x0(9); cmpw 0,31; beq 0b; addi 9,9,12; addi 11,11,1; 4:; li 0,0; beq cr7,5f; lwz 0,-4(3); 5:; cmpw 11,0; blt 3b; b 7f; 6:; addi 9,9,1; addi 3,3,8; cmpw 9,11; blt 2b; 7:; lwz 0,-24988(13); 8:; stw 0,0x0(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8003FE38_0();
extern "C" void f_8003FE38() {}
