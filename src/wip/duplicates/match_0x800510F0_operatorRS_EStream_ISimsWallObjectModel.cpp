struct EStorable;
struct EStream;
struct ISimsWallObjectModel;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, ISimsWallObjectModel*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (ISimsWallObjectModel*)storable;
    return stream;
}
