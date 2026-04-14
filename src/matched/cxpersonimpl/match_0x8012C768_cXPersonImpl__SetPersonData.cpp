// 0x8012C768 cXPersonImpl::SetPersonData (16B)

struct cXPerson_SPD {
    char pad[0x8];
    short m_arr[1];
    void SetPersonData(int index, short value);
};

void cXPerson_SPD::SetPersonData(int index, short value) {
    m_arr[index] = value;
}
