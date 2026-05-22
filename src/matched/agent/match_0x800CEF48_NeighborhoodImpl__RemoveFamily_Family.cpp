// 0x800CEF48 NeighborhoodImpl::RemoveFamily(Family (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lwz 9,0x0(30); lha 3,0x98(9); lwz 0,0x9c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 9,0x0(30); lha 3,0xa8(9); lwz 0,0xac(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; addi 9,31,92; lwz 3,0x5c(31); lwz 0,0x4(9); mr 31,9; cmpw 3,0; beq 3f; 0:; lwz 0,0x0(3); cmpw 0,30; bne 2f; lwz 5,0x4(31); addi 4,3,4; cmpw 4,5; beq 1f; cmpw 5,4; beq 1f; subf 5,4,5; bl _s800CEF48_0; 1:; lwz 9,0x4(31); mr 3,30; addi 9,9,-4; stw 9,0x4(31); bl _s800CEF48_1; li 3,0; b 4f; 2:; lwz 0,0x4(31); addi 3,3,4; cmpw 3,0; bne 0b; 3:; li 3,-1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800CEF48_0();
extern "C" void _s800CEF48_1();
extern "C" void f_800CEF48() {}
