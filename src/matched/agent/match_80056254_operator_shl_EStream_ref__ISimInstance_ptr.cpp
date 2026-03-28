class EStream;
class EStorable { };
class ISimInstance : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ISimInstance* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
