#include "ProcessData.h"
#include <boost/intrusive_ptr.hpp>
#include <string>

class Tn {
  public:
    std::string name = "syq";
};

int main()
{
    //Tn * t = new Tn();
    //std::cout << " new Tn " << std::endl;
    //delete t;
    //std::cout << " name size:" << t->name.size() << std::endl;

    boost::intrusive_ptr<ProcessData> ptr(new ProcessData(1, "a"));
    std::cout << "******************"<< std::endl;
    std::cout << "ref_count = " << ptr->RefCount() << std::endl;
    std::cout << "******************" << std::endl;
    {
        boost::intrusive_ptr<ProcessData> ptrCopy(ptr.get());
        std::cout << "ref_count after copy constructed = " << ptrCopy->RefCount() << std::endl;
    }

    std::cout << "******************" << std::endl;
    std::cout << "ref_count = " << ptr->RefCount() << std::endl;
    std::cout << "******************" << std::endl;

    {
        boost::intrusive_ptr<ProcessData> ptrAssignment = ptr;
        std::cout << "ref_count after assignment = " << ptrAssignment->RefCount() << std::endl;
    }

    std::cout << "******************" << std::endl;
    std::cout << "ref_count = " << ptr->RefCount() << std::endl;
    std::cout << "******************" << std::endl;

    boost::intrusive_ptr<ProcessData> ptrWeak0(ptr.get(), false);
    std::cout << " --------------------------------------------------- " << std::endl;
    {
        boost::intrusive_ptr<ProcessData> ptrWeak1(ptr.get(), false);
        std::cout << "ref_count after construct weak1_ptr = " << ptrWeak1->RefCount() << std::endl;
    }

    std::cout << "******************" << std::endl;
    std::cout << "ref_count = " << ptr->RefCount() << " m_info:" << ptr->m_info.c_str() << std::endl;
    std::cout << "******************" << std::endl;
    
    return 0;
}
