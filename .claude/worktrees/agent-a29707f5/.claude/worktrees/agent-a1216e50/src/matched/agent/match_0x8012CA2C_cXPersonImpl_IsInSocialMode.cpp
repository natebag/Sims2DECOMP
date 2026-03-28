/* cXPersonImpl::IsInSocialMode(void) - 0x8012CA2C - 24 bytes */
/* lha r0, 0x58(r3); li r3, 1; cmpwi r0, 0; bnelr; li r3, 0; blr */

class cXPersonImpl {
public:
    char _pad[0x58];
    short m_socialMode;

    int IsInSocialMode(void);
};

int cXPersonImpl::IsInSocialMode(void) {
    return m_socialMode != 0;
}
