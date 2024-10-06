#include <iostream>
#include <thread>   // For std::thread
#include <chrono>   // For delays (optional)

// Function for counting up to 20
void countUp() {
    for (int i = 1; i <= 20; i++) {
        std::cout << "Count Up: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Optional delay for visibility
    }
}

// Function for counting down from 20 to 0
void countDown() {
    for (int i = 20; i >= 0; i--) {
        std::cout << "Count Down: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Optional delay for visibility
    }
}

int main() {
    // Create and start the first thread to count up
    std::thread thread1(countUp);

    // Wait for thread1 to finish before starting thread2
    thread1.join();  // Ensures thread1 finishes counting up to 20

    // Create and start the second thread to count down
    std::thread thread2(countDown);

    // Wait for thread2 to finish
    thread2.join();

    return 0;
}



