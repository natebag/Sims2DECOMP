struct EStorable;
struct EStream;
struct ISimsMultiTileObjectModel;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, ISimsMultiTileObjectModel*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (ISimsMultiTileObjectModel*)storable;
    return stream;
}
