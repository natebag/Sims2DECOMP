// 0x80369840 (12 bytes)
class ERDataset {
public:
    const char* GetTypeName() const;
};

extern char gERDatasetData[];

const char* ERDataset::GetTypeName() const {
    return *(const char**)(gERDatasetData + 0);
}
