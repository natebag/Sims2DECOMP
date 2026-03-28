/* cXObjectImpl::SetMiscFlag(cXObject::MiscFlag, bool) - 32 bytes */

class cXObjectImpl {
public:
    char pad[0x84];
    int m_miscFlags;

    void SetMiscFlag(int flag, int set);
};

void cXObjectImpl::SetMiscFlag(int flag, int set) {
    m_miscFlags &= ~flag;
    if (set == 0) {
        return;
    }
    m_miscFlags |= flag;
}
