/* cXPerson::setPersonImpl(cXPersonImpl *) - 0x8012C684 - 16 bytes */
/* lwz r9, 0(r3); lwz r11, 0(r9); stw r4, 4(r11); blr */
/* Triple dereference: this->ptr->ptr->field4 = impl */

class cXPersonImpl;

struct cXPersonInnerInner {
    int m_field0;
    cXPersonImpl* m_impl;
};

struct cXPersonInner {
    cXPersonInnerInner* m_inner;
};

class cXPerson {
public:
    cXPersonInner* m_outer;

    void setPersonImpl(cXPersonImpl *impl);
};

void cXPerson::setPersonImpl(cXPersonImpl *impl) {
    cXPersonInner* inner = m_outer;
    cXPersonInnerInner* innerInner = inner->m_inner;
    innerInner->m_impl = impl;
}
