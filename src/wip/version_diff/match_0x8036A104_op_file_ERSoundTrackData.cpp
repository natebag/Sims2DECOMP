class EFile;
class ERSoundTrackData;

EFile& EResourceManager_LoadResource_EFile(EFile& file, unsigned int& handle);

EFile& operator>>(EFile& file, ERSoundTrackData*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EFile(file, handle);
    res = (ERSoundTrackData*)handle;
    return file;
}
