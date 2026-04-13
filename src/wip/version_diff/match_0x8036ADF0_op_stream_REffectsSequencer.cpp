class EStream;
class REffectsSequencer;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, REffectsSequencer*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (REffectsSequencer*)handle;
    return stream;
}
