/* cXPersonImpl::ClearIgnoringObject(void) - 0x8012CA20 - 12 bytes */
/* li r0, 0; stw r0, 0x53C(r3); blr */

class cXObject;

class cXPersonImpl {
public:
    char _pad[0x53C];
    cXObject* m_ignoringObject;

    void ClearIgnoringObject(void);
};

void cXPersonImpl::ClearIgnoringObject(void) {
    m_ignoringObject = 0;
}
