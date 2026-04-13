class EFile;
class ERSoundEvent;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, ERSoundEvent*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (ERSoundEvent*)handle;
    return file;
}
