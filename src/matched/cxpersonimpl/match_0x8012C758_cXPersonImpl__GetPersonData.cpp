// 0x8012C758 cXPersonImpl::GetPersonData (16B) const

struct cXPerson_GPD {
    char pad[0x8];
    short m_arr[1];
    short GetPersonData(int index) const;
};

short cXPerson_GPD::GetPersonData(int index) const {
    return m_arr[index];
}
