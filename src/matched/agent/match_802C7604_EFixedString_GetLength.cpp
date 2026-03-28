struct DataBlock_EFixedString_GetLength {
    int GetLength();
};
struct EFixedString_GetLength_S {
    DataBlock_EFixedString_GetLength* m_data;
    int GetLength() const;
};
int EFixedString_GetLength_S::GetLength() const {
    return m_data->GetLength();
}
