// 0x801386DC Room::Rotate(Room::Sides, int) (40B)
// ASMPROC_inject_before: before="bc 12,2,.L3" lines="li 3,0"
// ASMPROC_replace_insn: match="bc 12,2,.L3" replacement="bclr 12,2"
// ASMPROC_swap_adj: a=add b=addi which=first

struct Room {
    void Rotate();
};

void Room::Rotate() {
}
