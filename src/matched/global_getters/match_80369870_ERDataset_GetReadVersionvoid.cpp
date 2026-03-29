// 0x80369870 (12 bytes)
class ERDataset {
public:
    short GetReadVersion() const;
};

extern char gERDatasetData[];

short ERDataset::GetReadVersion() const {
    return *(short*)(gERDatasetData + 0);
}
