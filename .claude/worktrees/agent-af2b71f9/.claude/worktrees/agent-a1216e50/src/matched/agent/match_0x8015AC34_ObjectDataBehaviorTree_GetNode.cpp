/* ObjectDataBehaviorTree::GetNode(unsigned int) const - 0x8015AC34 - 20 bytes */
/* mulli r4, r4, 0xC; lwz r3, 0x54(r3); addi r4, r4, 0xC; add r3, r3, r4; blr */

class ObjectDataBehaviorTree {
public:
    char _pad[0x54];
    char* m_nodes;

    void* GetNode(unsigned int index) const;
};

void* ObjectDataBehaviorTree::GetNode(unsigned int index) const {
    return m_nodes + 0xC + index * 0xC;
}
