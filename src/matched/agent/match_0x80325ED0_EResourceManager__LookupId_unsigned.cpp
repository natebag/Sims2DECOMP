// 0x80325ED0 EResourceManager::LookupId(unsigned (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,5; mr 3,4; mr 29,6; lwz 4,0x4c(31); cmpwi 4,0; beq 0f; lwz 5,0x0(4); addi 4,4,4; bl _s80325ED0_0; cmpwi 3,-1; beq 0f; lwz 10,0x4c(31); add 11,3,3; addi 11,11,1; li 3,1; lwz 9,0x0(10); add 9,9,11; rlwinm 9,9,2,0,29; lwzx 0,9,10; stw 0,0x0(30); lwz 11,0x4c(31); add 9,9,11; lwz 0,0x4(9); stw 0,0x0(29); b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80325ED0_0();
extern "C" void f_80325ED0() {}
