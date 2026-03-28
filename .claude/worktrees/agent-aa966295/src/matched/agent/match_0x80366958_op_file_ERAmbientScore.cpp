class EFile;
class ERAmbientScore;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, ERAmbientScore*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (ERAmbientScore*)handle;
    return file;
}
