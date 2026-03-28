class CASPersonalTarget {
public:
    char _pad[0x8C];
    signed char m_savedPersVal[16];

    signed char GetSavedPersVal(signed char index);
};

signed char CASPersonalTarget::GetSavedPersVal(signed char index) {
    return m_savedPersVal[index];
}
