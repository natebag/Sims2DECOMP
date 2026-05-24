// 0x8022F50C EIStaticSubModel::HasModifiableColor(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x9c(3); li 10,0; cmpw 10,0; bge 4f; lwz 9,0x98(3); mr 8,0; addi 3,9,4; 0:; lwz 9,0x0(3); addi 3,3,16; lwz 0,0x14(9); cmpwi 0,0; beq 1f; mr 11,0; b 2f; 1:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 2f; lwz 11,0x14(9); 2:; lwz 9,0xb4(11); lwz 0,0x74(11); or 0,0,9; andi. 9,0,32; beq 3f; li 3,1; blr; 3:; addi 10,10,1; cmpw 10,8; blt 0b; 4:; li 3,0"

struct EIStaticSubModel {
    void HasModifiableColor();
};

void EIStaticSubModel::HasModifiableColor() {
}
