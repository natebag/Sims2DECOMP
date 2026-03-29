// ISimInstance::SetHighlight(unsigned int, bool)
// Address: 0x8005656C | Size: 40 bytes
// cmpwi r5, 0 / beq to AND-NOT path / fall-through: OR path

class ISimInstance {
public:
    void SetHighlight(unsigned int mask, bool value);
};

// layout: m_highlightFlags at offset 0x32C
struct ISimInstanceData {
    char _pad[0x32C];
    unsigned int m_highlightFlags;
};

void ISimInstance::SetHighlight(unsigned int mask, bool value) {
    ISimInstanceData *d = (ISimInstanceData *)this;
    if (value) {
        d->m_highlightFlags |= mask;
    } else {
        d->m_highlightFlags &= ~mask;
    }
}
