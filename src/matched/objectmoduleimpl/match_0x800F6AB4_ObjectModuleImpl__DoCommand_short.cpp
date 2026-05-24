// 0x800F6AB4 ObjectModuleImpl::DoCommand(short, (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 11,3; cmpwi 4,252; beq 6f; bgt 0f; cmpwi 4,134; beq 4f; cmpwi 4,238; beq 5f; b 8f; 0:; cmpwi 4,257; beq 3f; cmpwi 4,263; bne 8f; addi 29,11,8312; lwz 28,0x2078(11); mr 26,29; addi 27,1,16; lwz 30,0x4(29); mr 31,28; cmpw 28,30; beq 2f; 1:; lwz 9,0x0(31); li 4,2; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; addi 31,31,60; blrl; cmpw 31,30; bne 1b; 2:; lwz 4,-31848(13); mr 3,27; stw 28,0x4(29); bl _s800F6AB4_0; li 4,100; mr 6,26; li 5,0; li 7,0; li 8,0; mr 3,27; bl _s800F6AB4_1; mr 3,27; li 4,2; bl _s800F6AB4_2; b 9f; 3:; mr 3,11; bl _s800F6AB4_3; b 9f; 4:; lwz 9,0x0(11); lha 3,0xf0(9); lwz 0,0xf4(9); b 7f; 5:; lwz 9,0x0(11); mr 4,5; lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; beq 9f; lwz 9,0x4(31); lwz 0,0x30c(9); lha 3,0x308(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; ori 0,0,65531; cmpw 3,0; beq 9f; lwz 9,0x4(31); lha 3,0x308(9); lwz 0,0x30c(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; li 3,237; bl _s800F6AB4_4; b 9f; 6:; lwz 9,0x0(11); lha 3,0x178(9); lwz 0,0x17c(9); 7:; add 3,11,3; mtspr 8,0; blrl; b 9f; 8:; li 3,0; b 10f; 9:; li 3,1; 10:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s800F6AB4_0();
extern "C" void _s800F6AB4_1();
extern "C" void _s800F6AB4_2();
extern "C" void _s800F6AB4_3();
extern "C" void _s800F6AB4_4();

struct ObjectModuleImpl {
    void DoCommand_short();
};

void ObjectModuleImpl::DoCommand_short() {
}
