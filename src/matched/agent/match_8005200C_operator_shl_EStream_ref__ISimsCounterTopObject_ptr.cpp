class EStream;
class EStorable { };
class ISimsCounterTopObject : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ISimsCounterTopObject* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
