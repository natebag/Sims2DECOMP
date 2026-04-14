/* ObjectDataBehaviorTree::SetResourceName(StringBuffer &) - 0x8015AAD4 - 40 bytes */

struct StringBuffer {
    int copy(StringBuffer &);
};

struct ObjectDataBehaviorTree {
    char _pad[0x0C];
    StringBuffer m_name;

    int SetResourceName(StringBuffer &name);
};

int ObjectDataBehaviorTree::SetResourceName(StringBuffer &name) {
    m_name.copy(name);
    return 1;
}
