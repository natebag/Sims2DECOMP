// 0x800F111C ObjectFolderImpl::UnloadData(ObjSelector (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 11,0x3c(30); cmpwi 11,0; beq 0f; li 31,0; cmpw 31,11; beq 0f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 31,0x3c(30); 0:; lwz 3,0x80(30); cmpwi 3,0; beq 1f; bl _s800F111C_0; li 0,0; stw 0,0x80(30); 1:; lwz 11,0x64(30); li 31,0; cmpw 31,11; beq 3f; cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; stw 31,0x64(30); 3:; lwz 31,0x0(30); cmpwi 31,0; beq 5f; lwz 3,0x3c(29); cmpwi 3,0; beq 5f; mr 4,31; bl _s800F111C_1; cmpwi 3,0; beq 5f; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 9,0xc(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 5:; lwz 9,0x9c(30); li 0,0; stw 0,0x0(30); cmpwi 9,1; bne 6f; lwz 3,-21432(13); mr 4,30; bl _s800F111C_2; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800F111C_0();
extern "C" void _s800F111C_1();
extern "C" void _s800F111C_2();

struct ObjectFolderImpl {
    void UnloadData_ObjSelector();
};

void ObjectFolderImpl::UnloadData_ObjSelector() {
}
