// 0x801386DC Room::Rotate(Room::Sides, int) (40B)
// GCC emits: mr. 0,3; bc 12,2,exit; ...; exit: li 3,0; blr (11 insns)
// DOL wants: mr. 0,3; li 3,0; bclr 12,2; ...; blr (10 insns, beqlr inline)
// 3 directives: inject li 3,0 before the beq; replace bc with bclr; swap add↔addi-1
// ASMPROC_inject_before: before="bc 12,2,.L3" lines="li 3,0"
// ASMPROC_replace_insn: match="bc 12,2,.L3" replacement="bclr 12,2"
// ASMPROC_swap_adj: a=add b=addi which=first

struct Room {
    static int Rotate(int sides, int count);
};

int Room::Rotate(int sides, int count) {
    if (!sides)
        return 0;
    return ((sides + ((4 - count) & 3) - 1) & 3) + 1;
}
