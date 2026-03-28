class EStream;
class REffectsEmitter;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, REffectsEmitter*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (REffectsEmitter*)handle;
    return stream;
}
