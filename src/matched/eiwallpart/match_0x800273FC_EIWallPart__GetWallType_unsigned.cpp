// 0x800273FC EIWallPart::GetWallType(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; bne 0f; li 3,0; blr; 0:; cmpwi 3,4; beq 9f; bgt 1f; cmpwi 3,2; beq 7f; bgt 3f; cmpwi 3,1; beq 6f; b 11f; 1:; cmpwi 3,8; beq 10f; bgt 2f; cmpwi 3,6; beq 5f; b 11f; 2:; cmpwi 3,9; beq 4f; cmpwi 3,12; beq 8f; b 11f; 3:; li 3,1; blr; 4:; li 3,7; blr; 5:; li 3,8; blr; 6:; li 3,2; blr; 7:; li 3,3; blr; 8:; li 3,6; blr; 9:; li 3,4; blr; 10:; li 3,5; blr; 11:; li 3,0"

struct EIWallPart {
    void GetWallType();
};

void EIWallPart::GetWallType() {
}
