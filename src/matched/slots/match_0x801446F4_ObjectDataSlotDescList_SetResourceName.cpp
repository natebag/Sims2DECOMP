/* ObjectDataSlotDescList::SetResourceName(StringBuffer &) - 0x801446F4 - 40 bytes */

struct StringBuffer {
    int copy(StringBuffer &);
};

struct ObjectDataSlotDescList {
    char _pad[4];
    StringBuffer m_name;

    int SetResourceName(StringBuffer &name);
};

int ObjectDataSlotDescList::SetResourceName(StringBuffer &name) {
    m_name.copy(name);
    return 1;
}
