// 0x801CAA04 MODTarget::TriggerAspirationChestDisplay(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x88(31); cmpwi 0,0; beq 1f; lwz 0,0x94(31); cmpwi 0,0; bne 1f; lwz 29,0xe8(31); cmpwi 29,0; bne 0f; addi 30,31,200; lis 4,-32705; lis 5,-32705; addi 4,4,12604; addi 5,5,12800; mr 3,30; li 6,0; bl _s801CAA04_0; lwz 6,0x94(31); lis 4,-32705; addi 4,4,12632; mr 3,30; li 5,1; bl _s801CAA04_1; lis 4,-32705; lwz 6,0x94(31); mr 3,30; addi 4,4,12620; li 5,0; bl _s801CAA04_2; li 0,1; stw 29,0xf0(31); stw 0,0xec(31); 0:; li 0,120; stw 0,0xe8(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801CAA04_0();
extern "C" void _s801CAA04_1();
extern "C" void _s801CAA04_2();
extern "C" void f_801CAA04() {}
