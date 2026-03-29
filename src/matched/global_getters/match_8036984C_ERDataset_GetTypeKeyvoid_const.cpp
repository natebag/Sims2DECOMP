// 0x8036984C (12 bytes)
class ERDataset {
public:
    const char* GetTypeKey() const;
};

extern char gERDatasetData[];

const char* ERDataset::GetTypeKey() const {
    return *(const char**)(gERDatasetData + 0);
}
