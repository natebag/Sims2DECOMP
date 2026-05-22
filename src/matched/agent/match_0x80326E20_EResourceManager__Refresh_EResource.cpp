// 0x80326E20 EResourceManager::Refresh(EResource (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,4; li 0,0; lwz 4,0x8(31); addi 5,1,8; stw 0,0xc(1); bl _s80326E20_0; mr. 4,3; stw 3,0xc(1); beq 0f; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; lis 3,-32694; addi 4,1,12; addi 3,3,-10620; bl _s80326E20_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80326E20_0();
extern "C" void _s80326E20_1();
extern "C" void f_80326E20() {}
