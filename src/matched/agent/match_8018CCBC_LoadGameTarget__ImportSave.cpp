class NghResFile {
public:
    typedef int SectionID;
    struct SaveRecord {};
};

class LoadGameTarget {
public:
    void ImportSave(NghResFile::SectionID, NghResFile::SaveRecord &);
};

void LoadGameTarget::ImportSave(NghResFile::SectionID, NghResFile::SaveRecord &) {
}
