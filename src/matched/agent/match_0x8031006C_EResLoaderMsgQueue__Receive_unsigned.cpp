// 0x8031006C EResLoaderMsgQueue::Receive(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; addi 3,31,24; cmpwi 5,0; li 4,0; beq 0f; li 4,-1; 0:; bl _s8031006C_0; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; lwz 9,0x4c(31); addi 30,31,76; li 4,-1; lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 29,0; beq 2f; lwz 9,0x34(31); lwz 11,0x3c(31); rlwinm 9,9,2,0,29; lwzx 0,9,11; stw 0,0x0(29); 2:; lwz 9,0x34(31); lwz 11,0x38(31); addi 9,9,1; lwz 10,0x4c(31); divw 0,9,11; mullw 0,0,11; subf 9,0,9; stw 9,0x34(31); lha 3,0x18(10); lwz 0,0x1c(10); add 3,30,3; mtspr 8,0; blrl; mr 3,31; bl _s8031006C_1; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031006C_0();
extern "C" void _s8031006C_1();
extern "C" void f_8031006C() {}
