#include "n_container.h"

#include <gtest/gtest.h>

#include <iostream>


TEST(Vector_test, Empty) {
    N_Container<int> container;
    int container_size = container.size();
       
    EXPECT_EQ(container_size, 0);
}

TEST(Vector_test, container_size) {
    N_Container<int> container;
    const int count = 10;

     for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container.size(), count);
}

TEST(Vector_test, push_back) {
    N_Container<int> container;
    const int count = 10;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container.size(), count);
}

TEST(Vector_test, return_value_position_operator){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container[0], 0);
    ASSERT_EQ(container[4], 4);
    ASSERT_EQ(container[container.size()-1], 9);

 }

TEST(Vector_test, insert_first_position){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.insert(1,1000);

    ASSERT_EQ(container[0],1000);

}

TEST(Vector_test, insert_middle_position){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.insert(5,1000);

    ASSERT_EQ(container[4],1000);

}

TEST(Vector_test, erase_first_element){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(1);

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[0],1);

}

TEST(Vector_test, erase_middle_element){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(5);

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[4],5);

}

TEST(Vector_test, erase_last_element){
    const int count = 10;
    N_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(container.size());

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[container.size()-1],8);

}

