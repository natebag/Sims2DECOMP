// 0x800F7E34 ObjectModuleImpl::EnableBuyAndBuild(cXObject (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 9,0x0(30); lwz 0,0x224(9); lha 3,0x220(9); mtspr 8,0; add 3,30,3; blrl; mr 29,3; addi 9,30,8244; lwz 3,0x2034(30); lwz 0,0x4(9); cmpw 3,0; beq 5f; mr 11,9; cmpwi 7,31,0; 0:; lwz 9,0x0(3); cmpwi 9,0; beq 1f; lwz 0,0x4(9); cmpw 0,31; beq 2f; b 4f; 1:; bne cr7,4f; 2:; addi 31,30,8244; addi 4,3,4; lwz 5,0x4(31); cmpw 4,5; beq 3f; cmpw 5,4; beq 3f; subf 5,4,5; bl _s800F7E34_0; 3:; lwz 9,0x4(31); addi 9,9,-4; stw 9,0x4(31); b 5f; 4:; lwz 0,0x4(11); addi 3,3,4; cmpw 3,0; bne 0b; 5:; lwz 9,0x0(30); lha 3,0x220(9); lwz 0,0x224(9); add 3,30,3; mtspr 8,0; blrl; cmpw 29,3; beq 6f; li 3,260; li 4,0; bl _s800F7E34_1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800F7E34_0();
extern "C" void _s800F7E34_1();
extern "C" void f_800F7E34() {}
