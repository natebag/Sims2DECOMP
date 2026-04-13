class EFile;
class REffectsEmitter;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, REffectsEmitter*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (REffectsEmitter*)handle;
    return file;
}
