// 0x80037650 (4 bytes)
class NghResFile { public: typedef int SectionID; struct SaveRecord {}; };
class NghResFile;

namespace EyeToyClient {
    class NghResFile {
    public:
        enum SectionID {};
        class SaveRecord {};
    };

    void SaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &) {
        // Function does nothing
    }
}