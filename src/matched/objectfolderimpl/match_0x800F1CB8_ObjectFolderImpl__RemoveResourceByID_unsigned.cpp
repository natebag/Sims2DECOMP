// 0x800F1CB8 ObjectFolderImpl::RemoveResourceByID(unsigned (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 9,0x0(3); mr 29,5; mr 30,6; li 28,0; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 0f; lwz 9,0xc(31); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 9,0xc(31); mr 4,30; mr 5,29; li 6,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 3f; lwz 9,0xc(31); mr 4,3; lha 3,0x110(9); lwz 0,0x114(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; bl _s800F1CB8_0; cmpwi 3,0; beq 2f; mr 3,31; bl _s800F1CB8_1; mr 28,3; 2:; lwz 9,0xc(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; 3:; subfic 0,28,0; adde 3,0,28; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800F1CB8_0();
extern "C" void _s800F1CB8_1();

struct ObjectFolderImpl {
    void RemoveResourceByID();
};

void ObjectFolderImpl::RemoveResourceByID() {
}
