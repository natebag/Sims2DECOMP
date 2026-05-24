// 0x800F90E8 ObjectModuleImpl::FillInObjectStats(RoomManager (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 9,0x0(3); mr 26,4; mr 28,5; lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; b 6f; 0:; lwz 9,0x4(31); lha 3,0x438(9); lwz 0,0x43c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 0,0x20(28); lwz 9,-24292(13); b 2f; 1:; lwz 9,0x4(31); lha 3,0x440(9); lwz 0,0x444(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 0,0x20(28); lwz 9,-24296(13); 2:; add 0,0,9; stw 0,0x20(28); 3:; lwz 9,0x4(31); lha 3,0x430(9); lwz 0,0x434(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; lwz 9,0x24(28); addi 9,9,1; stw 9,0x24(28); lwz 11,0x4(31); lha 3,0x3c8(11); lwz 0,0x3cc(11); add 3,31,3; mtspr 8,0; blrl; mr. 27,3; ble 5f; lwz 9,0x4(31); lwz 29,-21488(13); lha 3,0x340(9); lwz 9,0x344(9); lwz 30,0x0(29); add 3,31,3; mtspr 8,9; lha 0,0x68(30); addi 30,30,104; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 5f; lwz 9,0x4(31); lha 3,0x308(9); lwz 0,0x30c(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 3,26; bl _s800F90E8_0; mr. 3,3; beq 5f; bl _s800F90E8_1; cmpwi 3,0; beq 4f; lwz 0,0x1c(28); add 0,0,27; stw 0,0x1c(28); b 5f; 4:; lwz 0,0x18(28); add 0,0,27; stw 0,0x18(28); 5:; lwz 9,0x4(31); lha 3,0x490(9); lwz 0,0x494(9); add 3,31,3; mtspr 8,0; 6:; blrl; mr. 31,3; bne 0b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800F90E8_0();
extern "C" void _s800F90E8_1();

struct ObjectModuleImpl {
    void FillInObjectStats_RoomManager();
};

void ObjectModuleImpl::FillInObjectStats_RoomManager() {
}
