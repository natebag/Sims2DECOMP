class NghResFile {
public:
    typedef int SectionID;
    struct SaveRecord {};
};

class LoadGameTarget {
public:
    void ImportLoad(NghResFile::SectionID, NghResFile::SaveRecord &);
};

void LoadGameTarget::ImportLoad(NghResFile::SectionID, NghResFile::SaveRecord &) {
}
