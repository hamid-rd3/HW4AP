#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
int main(int argc, char** argv)
{
    if (true) // make false to run unit-tests
    {
        int x { 10 };
         int* y { make_unique<int>(x)};
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