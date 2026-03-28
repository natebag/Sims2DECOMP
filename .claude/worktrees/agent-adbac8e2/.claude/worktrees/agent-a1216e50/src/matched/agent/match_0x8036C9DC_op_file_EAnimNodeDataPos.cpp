class EFile;
class EAnimNodeDataPos;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, EAnimNodeDataPos*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (EAnimNodeDataPos*)handle;
    return file;
}
