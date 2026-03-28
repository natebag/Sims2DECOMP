/* cXObjectImpl::HaveGraphicsBeenTagged(void) - 40 bytes */

class cXObjectImpl {
public:
    char pad[0xE8];
    int m_graphicsFieldTag;

    int HaveGraphicsBeenTagged(void);
};

int cXObjectImpl::HaveGraphicsBeenTagged(void) {
    if (m_graphicsFieldTag != 0) {
        m_graphicsFieldTag = 0;
        return 1;
    }
    return 0;
}
