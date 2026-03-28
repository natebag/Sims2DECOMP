class EStream;
class ERCharacter;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, ERCharacter*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (ERCharacter*)handle;
    return stream;
}
