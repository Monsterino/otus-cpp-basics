#include "p_container.h"

#include <gtest/gtest.h>

#include <iostream>


TEST(List_test, Empty) {
    P_Container<int> container;
    const int expected = 0;

    ASSERT_EQ(container.size(), expected);
}

TEST(List_test, container_size) {
    P_Container<int> container;
    const int count = 10;

     for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container.size(), count);
}

TEST(List_test, push_back) {
    P_Container<int> container;
    const int count = 10;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container.size(), count);
}

TEST(List_test, return_value_position_operator){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    ASSERT_EQ(container[0], 0);
    ASSERT_EQ(container[4], 4);
    ASSERT_EQ(container[container.size()-1], 9);

 }

TEST(List_test, insert_first_position){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.insert(1,1000);

    ASSERT_EQ(container[0],1000);

}

TEST(List_test, insert_middle_position){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.insert(5,1000);

    ASSERT_EQ(container[4],1000);

}

TEST(List_test, erase_first_element){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(1);

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[0],1);

}

TEST(List_test, erase_middle_element){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(5);

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[4],5);

}

TEST(List_test, erase_last_element){
    const int count = 10;
    P_Container<int> container;

    for (size_t i = 0; i < count; ++i) {
        container.push_back(i);
    }

    container.erase(container.size());

    ASSERT_EQ(container.size(),9);
    ASSERT_EQ(container[container.size()-1],8);

}
