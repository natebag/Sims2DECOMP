// 0x80369858 (12 bytes)
class ERDataset {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short gERDatasetData[];

unsigned short ERDataset::GetTypeVersion() const {
    return gERDatasetData[0];
}
