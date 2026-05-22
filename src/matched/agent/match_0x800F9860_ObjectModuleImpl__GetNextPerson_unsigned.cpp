// 0x800F9860 ObjectModuleImpl::GetNextPerson(unsigned (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x2058(3); mr 29,4; addi 3,3,8280; lwz 11,0x4(3); subf 0,9,11; rlwinm. 10,0,30,2,31; beq 4f; cmpwi 29,0; bne 1f; lwz 9,0x0(9); 0:; li 3,0; cmpwi 9,0; beq 5f; lwz 3,0x4(9); b 5f; 1:; mr 31,9; cmpw 31,11; beq 4f; mr 30,3; 2:; lwz 9,0x0(31); lwz 11,0x0(9); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x328(9); lwz 0,0x32c(9); add 3,10,3; mtspr 8,0; blrl; cmpw 3,29; bne 3f; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; beq 4f; lwz 9,0x0(31); b 0b; 3:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 2b; 4:; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800F9860() {}
