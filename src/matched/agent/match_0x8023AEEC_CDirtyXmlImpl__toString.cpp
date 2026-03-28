extern int CDirtyXmlNode_toString(void *self);

struct CDirtyXmlImpl {
    int toString();
};

int CDirtyXmlImpl::toString() {
    return CDirtyXmlNode_toString(this);
}
