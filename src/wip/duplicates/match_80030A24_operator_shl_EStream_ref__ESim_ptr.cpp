class EStream;
class EStorable { };
class ESim : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ESim* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
