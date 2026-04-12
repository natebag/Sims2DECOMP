// 0x80369870 (12 bytes)
class ERDataset {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short gERDatasetData[];

unsigned short ERDataset::GetReadVersion() const {
    return gERDatasetData[1];
}
