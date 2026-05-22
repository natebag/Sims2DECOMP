// 0x80329154 FreeResourceManager::RemoveItem(EResource (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; li 4,-1; bl _s80329154_0; lwz 11,0xca0(31); li 10,0; cmpw 10,11; bge 1f; lwz 0,0x20(31); addi 9,31,32; cmpw 0,30; beq 1f; 0:; addi 10,10,1; cmpw 10,11; bge 1f; lwzu 0,0x4(9); cmpw 0,30; bne 0b; 1:; lwz 9,0xca0(31); addi 9,9,-1; cmpw 10,9; bge 3f; rlwinm 9,10,2,0,29; addi 9,9,32; add 11,9,31; 2:; lwz 0,0x4(11); addi 10,10,1; stw 0,0x0(11); addi 11,11,4; lwz 9,0xca0(31); addi 9,9,-1; cmpw 10,9; blt 2b; 3:; lwz 9,0xca0(31); mr 3,31; addi 9,9,-1; stw 9,0xca0(31); bl _s80329154_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80329154_0();
extern "C" void _s80329154_1();
extern "C" void f_80329154() {}
