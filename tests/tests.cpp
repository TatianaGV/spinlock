#include <gtest/gtest.h>
#include <thread>
#include "spinlock.hpp"
#include <iostream>

spinlock::SpinLock spinlocker;
unsigned int counter;
const int T_COUNT = 10;

void count() {
    for (size_t i = 0; i < 50010; i++) {
        spinlocker.lock();
        counter++;
        spinlocker.unlock();
    }
}

TEST(oneThread, lock) {
    spinlock::SpinLock spin;
    spin.lock();
    ASSERT_EQ(spin.try_lock(), false);
}

TEST(oneThread, unlock) {
    spinlock::SpinLock spin;
    spin.lock();
    spin.unlock();
    ASSERT_EQ(spin.try_lock(), true);
}

TEST(oneThread, try_lock) {
    spinlock::SpinLock spin;
    ASSERT_EQ(spin.try_lock(), true);
    ASSERT_EQ(spin.try_lock(), false);
}

TEST(multipleThreads, dataRace) {
    std::thread t[T_COUNT];
    for (size_t i = 0; i < T_COUNT; i++)
        t[i] = std::thread(count);
    for (size_t i = 0; i < T_COUNT; i++)
        t[i].join();
    ASSERT_EQ(count, 500100);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}