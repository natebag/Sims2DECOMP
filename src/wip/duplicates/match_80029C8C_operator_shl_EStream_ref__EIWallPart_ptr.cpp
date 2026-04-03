class EStream;
class EStorable;
class EIWallPart;

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, EIWallPart* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
