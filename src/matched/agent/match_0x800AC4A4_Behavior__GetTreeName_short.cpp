// 0x800AC4A4 Behavior::GetTreeName(short, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); li 0,0; mr 31,5; stw 0,0x8(1); addi 5,1,8; cmpwi 4,255; bgt 0f; lwz 3,0x8(3); mr 5,31; lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; cmpwi 4,9000; ble 2f; lis 4,-32706; mr 3,31; addi 4,4,-27876; li 5,-1; bl _s800AC4A4_0; 1:; lwz 11,0x8(1); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 5f; 2:; li 6,1; bl _s800AC4A4_1; cmpwi 3,0; beq 3f; lwz 3,0x8(1); mr 4,31; lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; b 4f; 3:; mr 3,31; bl _s800AC4A4_2; 4:; lwz 11,0x8(1); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800AC4A4_0();
extern "C" void _s800AC4A4_1();
extern "C" void _s800AC4A4_2();
extern "C" void f_800AC4A4() {}
