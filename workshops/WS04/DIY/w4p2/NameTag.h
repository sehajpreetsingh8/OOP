//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#ifndef SDDS_BOX_H // replace with relevant names
#define SDDS_BOX_H
namespace sdds {
	class NameTag
	{
        char* m_name;
        int m_extension;
        void setName(const char* Cstr);
        
    public:
        NameTag();
        NameTag(const char* name);
        NameTag(const char* name, int extension);
        ~NameTag();
        void flushkeys();
        void print();
        NameTag& read();
        bool checkValid();
        
	};
}
#endif