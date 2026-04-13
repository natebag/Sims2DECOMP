class EFile;
class ERDataset;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, ERDataset*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (ERDataset*)handle;
    return file;
}
