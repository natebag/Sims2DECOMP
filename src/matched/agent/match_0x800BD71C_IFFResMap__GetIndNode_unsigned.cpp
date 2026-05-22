// 0x800BD71C IFFResMap::GetIndNode(unsigned (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,5; mr 29,6; li 5,0; bl _s800BD71C_0; lwz 0,0x4(30); cmpw 3,0; beq 1f; cmpwi 29,0; beq 0f; stw 29,0x14(3); 0:; cmpwi 31,0; ble 1f; lwz 11,0x0(3); lis 9,-17874; lwz 0,0x4(3); ori 9,9,35747; subf 0,11,0; mullw 0,0,9; srawi 0,0,3; cmpw 31,0; bgt 1f; mulli 3,31,88; add 3,11,3; addi 3,3,-88; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800BD71C_0();
extern "C" void f_800BD71C() {}
