struct DataBlock_EString_GetLength {
    int GetLength();
};
struct EString_GetLength_S {
    DataBlock_EString_GetLength* m_data;
    int GetLength() const;
};
int EString_GetLength_S::GetLength() const {
    return m_data->GetLength();
}
