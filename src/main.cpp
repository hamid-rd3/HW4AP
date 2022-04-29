#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        SharedPtr<int> ptr1{new int{10}};
         SharedPtr<int> ptr2{ptr1};

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