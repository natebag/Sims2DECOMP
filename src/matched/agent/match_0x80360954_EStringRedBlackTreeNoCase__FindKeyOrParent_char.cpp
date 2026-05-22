// 0x80360954 EStringRedBlackTreeNoCase::FindKeyOrParent(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 30,0x8(3); lis 9,-32700; addi 9,9,11816; mr 29,4; li 31,0; cmpw 30,9; beq 4f; mr 28,9; 0:; addi 31,30,28; mr 4,29; mr 3,31; bl _s80360954_0; cmpwi 3,0; bne 1f; mr 3,30; b 5f; 1:; mr 3,31; mr 4,29; bl _s80360954_1; mr 31,30; cmpwi 3,0; ble 2f; lwz 3,0x0(31); b 3f; 2:; lwz 3,0x4(31); 3:; mr 30,3; cmpw 30,28; bne 0b; 4:; mr 3,31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80360954_0();
extern "C" void _s80360954_1();
extern "C" void f_80360954() {}
