// 0x8018CCC0 (4 bytes)
class LoadGameTarget {
public:
    enum SectionID {};
    struct SaveRecord;
    void ImportSaveComplete(SectionID, SaveRecord &);
};

void LoadGameTarget::ImportSaveComplete(SectionID, SaveRecord &) {}
