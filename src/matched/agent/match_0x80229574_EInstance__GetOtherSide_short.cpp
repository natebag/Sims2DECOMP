// 0x80229574 EInstance::GetOtherSide(short (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x20(3); mr 6,5; cmpwi 0,0; beq 0f; mr 5,4; lwz 3,0x24(3); li 4,0; mtspr 8,0; blrl; b 1f; 0:; li 0,-1; sth 0,0x0(6); sth 0,0x0(4); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80229574() {}
