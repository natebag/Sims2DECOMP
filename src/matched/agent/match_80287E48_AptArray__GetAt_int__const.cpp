struct AptValue;

struct AptArray {
    char pad[0x24];
    AptValue** m_data;

    AptValue* GetAt(int index) const;
};

AptValue* AptArray::GetAt(int index) const {
    return m_data[index];
}
