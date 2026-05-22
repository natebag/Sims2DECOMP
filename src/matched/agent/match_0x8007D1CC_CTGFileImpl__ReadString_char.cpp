// 0x8007D1CC CTGFileImpl::ReadString(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x0(31); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lbz 0,0x8(1); cmpwi 0,255; bne 0f; lwz 9,0x0(31); addi 4,1,12; lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; stw 0,0xc(1); 1:; lwz 9,0x0(31); mr 4,30; lwz 5,0xc(1); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; 2:; li 3,0; b 4f; 3:; lwz 9,0xc(1); li 0,0; li 3,1; stbx 0,30,9; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_8007D1CC() {}
