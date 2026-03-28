struct DataBlock_EString2_GetLength {
    int GetLength();
};
struct EString2_GetLength_S {
    DataBlock_EString2_GetLength* m_data;
    int GetLength() const;
};
int EString2_GetLength_S::GetLength() const {
    return m_data->GetLength();
}
