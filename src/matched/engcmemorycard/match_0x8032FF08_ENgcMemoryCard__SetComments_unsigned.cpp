// 0x8032FF08 ENgcMemoryCard::SetComments(unsigned (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x0(3); li 11,0; cmpwi 0,0; beq 3f; lis 9,-32700; li 7,153; addi 8,9,-4416; 0:; add 9,11,11; lhzx 0,9,3; add 10,9,3; cmpwi 0,8482; bne 1f; stbx 7,8,11; b 2f; 1:; lbz 0,0x1(10); stbx 0,8,11; 2:; addi 0,11,1; rlwinm 11,0,0,24,31; cmplwi 11,32; bge 4f; add 0,11,11; lhzx 9,3,0; cmpwi 9,0; bne 0b; 3:; cmplwi 11,32; bge 4f; lis 9,-32700; li 0,0; addi 9,9,-4416; stbx 0,9,11; b 5f; 4:; lis 9,-32700; li 0,0; stb 0,-4385(9); 5:; lhz 0,0x0(4); li 11,0; cmpwi 0,0; beq 9f; lis 9,-32700; li 7,153; addi 8,9,-4384; 6:; add 9,11,11; lhzx 0,9,4; add 10,9,4; cmpwi 0,8482; bne 7f; stbx 7,8,11; b 8f; 7:; lbz 0,0x1(10); stbx 0,8,11; 8:; addi 0,11,1; rlwinm 11,0,0,24,31; cmplwi 11,32; bge 10f; add 0,11,11; lhzx 9,4,0; cmpwi 9,0; bne 6b; 9:; cmplwi 11,32; bge 10f; lis 9,-32700; li 0,0; addi 9,9,-4416; addi 9,9,32; stbx 0,9,11; blr; 10:; lis 9,-32700; li 0,0; stb 0,-4353(9)"

struct ENgcMemoryCard {
    void SetComments();
};

void ENgcMemoryCard::SetComments() {
}
