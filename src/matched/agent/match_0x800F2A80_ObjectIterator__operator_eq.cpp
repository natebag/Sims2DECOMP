// 0x800F2A80 ObjectIterator::operator==(ObjectIterator&) const (64B)
// DOL: mr r10,r3; loads OTHER first in both list and node checks
// other-first operand order forces compiler to pre-copy this→r10

struct ObjectIterator {
    void* m_node;   // +0
    void* m_list;   // +4
    bool operator==(ObjectIterator& other) const;
};

bool ObjectIterator::operator==(ObjectIterator& other) const {
    const ObjectIterator* self = this;
    void* other_list = other.m_list;
    if (other_list != self->m_list) goto ret_false;
    if (other_list) goto check_nodes;
    return true;
check_nodes:
    if (other.m_node == self->m_node) return true;
ret_false:
    return false;
}
