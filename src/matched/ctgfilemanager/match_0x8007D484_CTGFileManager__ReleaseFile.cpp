// 0x8007D484 CTGFileManager::ReleaseFile(CTGFile*) (64B)

class CTGFile {
public:
    virtual void Release(int n) = 0;
};

class CTGFileManager {
public:
    void ReleaseFile(CTGFile* file);
};

void CTGFileManager::ReleaseFile(CTGFile* file) {
    if (file == 0) return;
    file->Release(3);
}
