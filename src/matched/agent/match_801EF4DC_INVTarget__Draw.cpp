class ERC;

class SomeBase {
public:
    void Draw(ERC*);
};

class INVTarget {
public:
    char pad[0x319C];
    SomeBase m_base;
    void Draw(ERC* erc);
};

void INVTarget::Draw(ERC* erc) {
    m_base.Draw(erc);
}
