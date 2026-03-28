class EStream;
class ERAmbientScore;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, ERAmbientScore*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (ERAmbientScore*)handle;
    return stream;
}
