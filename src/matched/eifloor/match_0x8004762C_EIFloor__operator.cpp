// 0x8004762C EIFloor::operator (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-32508(13); cmpwi 9,0; beq 1f; lwz 3,0x0(9); cmpwi 3,0; beq 0f; lwz 0,0x0(3); stw 0,0x0(9); 0:; beqlr; lwz 9,-32504(13); addi 9,9,1; stw 9,-32504(13); blr; 1:; li 3,0"

struct EIFloor {
    void operator();
};

void EIFloor::operator() {
}
