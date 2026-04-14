/* IFFBehaviorConstants::SetResourceName(StringBuffer &) - 0x8015A57C - 40 bytes */

struct StringBuffer {
    int copy(StringBuffer &);
};

struct IFFBehaviorConstants {
    char _pad[0x18];
    StringBuffer m_name;

    int SetResourceName(StringBuffer &name);
};

int IFFBehaviorConstants::SetResourceName(StringBuffer &name) {
    m_name.copy(name);
    return 1;
}
