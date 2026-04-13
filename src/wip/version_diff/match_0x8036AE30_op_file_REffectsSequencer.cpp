class EFile;
class REffectsSequencer;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, REffectsSequencer*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (REffectsSequencer*)handle;
    return file;
}
