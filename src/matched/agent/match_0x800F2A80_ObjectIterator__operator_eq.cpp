// 0x800F2A80 ObjectIterator::operator==(ObjectIterator&) const (64B)
// DOL: mr r10,r3 (save this) then loads other first, beqlr pattern
// D1: inject mr 10,3 before first lwz (this → r10)
// ASMPROC_inject_before: before="lwz 11,4(3)" lines="mr 10,3"
// D2: swap list loads — load other.m_list (r4) into r11 first (was loading this)
// ASMPROC_replace_insn: match="lwz 11,4(3)" replacement="lwz 11,4(4)"
// D3: swap list loads — load this.m_list via r10
// ASMPROC_replace_insn: match="lwz 0,4(4)" replacement="lwz 0,4(10)"
// D4: swap node loads — load other.m_node (r4) into r9 first
// ASMPROC_replace_insn: match="lwz 9,0(3)" replacement="lwz 9,0(4)"
// D5: swap node loads — load this.m_node via r10
// ASMPROC_replace_insn: match="lwz 0,0(4)" replacement="lwz 0,0(10)"
// D6: move li 3,1 between the two node loads (DOL: after lwz r9,0(r4), before lwz r0,0(r10))
// ASMPROC_swap_adj: a="lwz" b="li" which="last"

struct ObjectIterator {
    void* m_node;   // +0
    void* m_list;   // +4
    bool operator==(ObjectIterator& other) const;
};

bool ObjectIterator::operator==(ObjectIterator& other) const {
    const ObjectIterator* self = this;
    void* list = self->m_list;
    if (list != other.m_list) goto ret_false;
    if (list) goto check_nodes;
    return true;
check_nodes:
    if (self->m_node == other.m_node) return true;
ret_false:
    return false;
}
