// 0x8004A7A0 BBI::InventoryItems::GetItemCount(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; bl _s8004A7A0_0; mr 0,3; cmpw 31,0; bge 2f; mtspr 9,0; mr 3,30; 0:; lwz 0,0x0(3); addi 3,3,4; cmpwi 0,0; beq 1f; addi 31,31,1; 1:; bdnz 0b; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004A7A0_0();
extern "C" void f_8004A7A0() {}
