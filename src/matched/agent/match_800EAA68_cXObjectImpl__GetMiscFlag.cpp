/* cXObjectImpl::GetMiscFlag(cXObject::MiscFlag) - 24 bytes */

class cXObjectImpl {
public:
    char pad[0x84];
    int m_miscFlags;

    int GetMiscFlag(int flag);
};

int cXObjectImpl::GetMiscFlag(int flag) {
    if (m_miscFlags & flag) {
        return 1;
    }
    return 0;
}
