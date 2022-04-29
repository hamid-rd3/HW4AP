#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
    SharedPtr<std::string> ptr1{make_shared<std::string>("hello world!")};
    SharedPtr<std::string> ptr2{ptr1};
    SharedPtr<std::string> ptr3{ptr1};
     SharedPtr<std::string> ptr4{ptr1};

    std::cout <<ptr1.use_count()<<ptr2.use_count()<<ptr3.use_count()<< ptr4.use_count()<< std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}