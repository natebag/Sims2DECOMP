class EStream;
class ERSoundTrackData;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, ERSoundTrackData*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (ERSoundTrackData*)handle;
    return stream;
}
