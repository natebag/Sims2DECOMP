class EStream;
class EStorable { };
class EIFloor : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, EIFloor* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
