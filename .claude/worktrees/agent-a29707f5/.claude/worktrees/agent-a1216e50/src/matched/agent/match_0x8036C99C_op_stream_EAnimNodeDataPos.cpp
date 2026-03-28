class EStream;
class EAnimNodeDataPos;

EStream& EResourceManager_LoadResource_EStream(EStream& stream, unsigned int& handle);

EStream& operator>>(EStream& stream, EAnimNodeDataPos*& res)
{
    unsigned int handle;
    EResourceManager_LoadResource_EStream(stream, handle);
    res = (EAnimNodeDataPos*)handle;
    return stream;
}
