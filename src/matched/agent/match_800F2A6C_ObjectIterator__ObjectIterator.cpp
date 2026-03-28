/* ObjectIterator::ObjectIterator(cXObject *, ObjectIterator::IterateType) - 20 bytes */

class cXObject;

class ObjectIterator {
public:
    cXObject* m_current;
    cXObject* m_object;
    int m_iterateType;

    ObjectIterator(cXObject* obj, int iterateType);
};

ObjectIterator::ObjectIterator(cXObject* obj, int iterateType) {
    m_current = obj;
    m_object = obj;
    m_iterateType = iterateType;
}
