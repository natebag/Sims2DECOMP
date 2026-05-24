// 0x800F2084 ObjectFolderImpl::GetStringFromNamespaceID(unsigned (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,5; mr 29,3; mr 28,6; mr 31,7; mr 30,4; mr 3,27; bl _s800F2084_0; lwz 9,0x0(29); mr 4,30; lha 3,0x198(9); lwz 0,0x19c(9); add 3,29,3; mtspr 8,0; blrl; mr 4,28; bl _s800F2084_1; mr. 30,3; beq 0f; cmpwi 31,0; ble 0f; lwz 9,0x0(30); li 4,-1; lha 3,0x70(9); lwz 0,0x74(9); add 3,30,3; mtspr 8,0; blrl; cmpw 31,3; ble 1f; 0:; li 3,0; b 2f; 1:; lwz 9,0x0(30); mr 4,31; li 5,-1; lha 3,0x80(9); lwz 0,0x84(9); add 3,30,3; mtspr 8,0; blrl; mr 4,3; li 5,-1; mr 3,27; bl _s800F2084_2; li 3,1; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800F2084_0();
extern "C" void _s800F2084_1();
extern "C" void _s800F2084_2();

struct ObjectFolderImpl {
    void GetStringFromNamespaceID();
};

void ObjectFolderImpl::GetStringFromNamespaceID() {
}
