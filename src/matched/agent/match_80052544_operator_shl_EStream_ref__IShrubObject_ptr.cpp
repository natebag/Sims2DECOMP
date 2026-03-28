class EStream;
class EStorable { };
class IShrubObject : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, IShrubObject* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
