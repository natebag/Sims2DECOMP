// 0x800F165C ObjectFolderImpl::GetAnimPreloadList(ChecksumList (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 22,0x18(1); stw 0,0x44(1); li 0,0; mr 22,3; stw 0,0x10(1); mr 26,4; lwz 11,0x3c(22); lwz 23,0x4(11); stw 23,0x8(1); lwz 9,0x4(11); lwz 0,0x8(9); stw 0,0x10(1); stw 0,0x8(1); b 8f; 0:; lwz 9,0x18(9); lwz 0,0x440(22); cmpw 9,0; beq 7f; lwz 9,0x8(9); li 25,0; lwzu 11,0x4(9); mr 24,9; cmpwi 11,0; beq 1f; lwz 25,-4(11); 1:; li 8,0; cmpw 8,25; bge 7f; 2:; lwz 11,0x0(24); rlwinm 9,8,3,0,28; li 0,0; lwzx 10,11,9; add 28,11,9; cmpwi 10,0; beq 3f; lwz 0,-4(10); 3:; addi 27,8,1; cmpwi 0,0; ble 6f; mr 30,0; li 29,0; 4:; lwz 9,0x0(28); lwzx 3,9,29; addi 29,29,4; cmpwi 3,0; beq 5f; lwz 31,0x0(3); mr 4,26; cmpwi 31,0; beq 5f; lwz 3,0x0(31); bl _s800F165C_0; cmpwi 3,0; mr 3,26; bne 5f; lwz 4,0x0(31); bl _s800F165C_1; 5:; addic. 30,30,-1; bne 4b; 6:; mr 8,27; cmpw 8,25; blt 2b; 7:; lwz 3,0x10(1); bl _s800F165C_2; stw 3,0x10(1); 8:; lwz 9,0x10(1); li 0,1; cmpw 9,23; bne 9f; li 0,0; 9:; cmpwi 0,0; bne 0b; lwz 0,0x44(1); mtspr 8,0; lmw 22,0x18(1); addi 1,1,64"

extern "C" void _s800F165C_0();
extern "C" void _s800F165C_1();
extern "C" void _s800F165C_2();

struct ObjectFolderImpl {
    void GetAnimPreloadList_ChecksumList();
};

void ObjectFolderImpl::GetAnimPreloadList_ChecksumList() {
}
