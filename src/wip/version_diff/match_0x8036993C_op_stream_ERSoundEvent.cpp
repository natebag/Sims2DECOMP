class EStream;
class ERSoundEvent;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, ERSoundEvent*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (ERSoundEvent*)handle;
    return stream;
}
