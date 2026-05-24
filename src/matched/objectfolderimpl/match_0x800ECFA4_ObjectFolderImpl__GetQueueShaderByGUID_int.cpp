// 0x800ECFA4 ObjectFolderImpl::GetQueueShaderByGUID(int) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x54(3); li 8,0; lwz 10,0x0(9); cmpwi 7,10,0; mr 11,10; b 2f; 0:; lwz 9,0x0(11); lwz 9,0xc0(9); cmpwi 9,0; beq 1f; lwz 3,0x1c(9); b 4f; 1:; addi 11,11,4; addi 8,8,1; 2:; li 0,0; beq cr7,3f; lwz 0,-4(10); 3:; cmpw 8,0; blt 0b; li 3,0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ObjectFolderImpl {
    void GetQueueShaderByGUID();
};

void ObjectFolderImpl::GetQueueShaderByGUID() {
}
