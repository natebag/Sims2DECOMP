// FLAGS: -fno-elide-constructors
// 0x8023AC98 CDirtyXml::getNextAttribute (52b)

void* CDirtyXml_getNextAttribute(void* self) {
    xml_getnextattr_impl(self);
    return self;
}
