cmake_minimum_required(VERSION 3.10)

project(randomcpp)

option(ENABLE_TESTING "Enable Testing" OFF)
if(${ENABLE_TESTING})
        include(FetchContent)
        FetchContent_Declare(
          googletest
          URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        )
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
        enable_testing()

        add_executable(lcg test/test_lcg.cpp)
        target_include_directories(lcg PUBLIC include)

        add_executable(pcg test/test_pcg.cpp)
        target_include_directories(pcg PUBLIC include)

        include(GoogleTest)
        # gtest_discover_tests(test_staticarrays)
endif()