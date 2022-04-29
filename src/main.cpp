#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
int main(int argc, char** argv)
{
    if (true) // make false to run unit-tests
    {
        SharedPtr<int> ptr1 { make_shared<int>(10) };
        std::cout << ptr1.use_count() << std::endl; // output: 1
        SharedPtr<int> ptr2 { ptr1 };
        std::cout << ptr1.use_count() << std::endl; // output: 2
        std::cout << ptr2.use_count() << std::endl; // output: 2

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