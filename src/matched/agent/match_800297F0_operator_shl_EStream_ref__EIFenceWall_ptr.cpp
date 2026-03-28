class EStream;
class EStorable;
class EIFenceWall;

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, EIFenceWall* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
