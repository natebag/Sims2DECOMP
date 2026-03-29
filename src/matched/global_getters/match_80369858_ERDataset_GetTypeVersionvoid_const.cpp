// 0x80369858 (12 bytes)
class ERDataset {
public:
    short GetTypeVersion() const;
};

extern char gERDatasetData[];

short ERDataset::GetTypeVersion() const {
    return *(short*)(gERDatasetData + 0);
}
