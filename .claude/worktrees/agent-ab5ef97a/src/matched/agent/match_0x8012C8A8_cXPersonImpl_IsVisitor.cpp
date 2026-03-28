/* cXPersonImpl::IsVisitor(void) - 0x8012C8A8 - 24 bytes */
/* lha r0, 0x48(r3); li r3, 1; cmpwi r0, 0; bnelr; li r3, 0; blr */

class cXPersonImpl {
public:
    char _pad[0x48];
    short m_visitorStatus;

    int IsVisitor(void);
};

int cXPersonImpl::IsVisitor(void) {
    return m_visitorStatus != 0;
}
