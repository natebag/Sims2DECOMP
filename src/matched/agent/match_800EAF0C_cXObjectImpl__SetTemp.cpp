/* cXObjectImpl::SetTemp(int, short) - 16 bytes */

class cXObjectImpl {
public:
    char pad[0x16];
    short m_temps[1];

    void SetTemp(int index, short value);
};

void cXObjectImpl::SetTemp(int index, short value) {
    m_temps[index] = value;
}
