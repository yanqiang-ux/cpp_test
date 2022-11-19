#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <thread>
#include <vector>

static constexpr int BLOCK_SIZE = 10000;
static constexpr int NUM_THREADS = 32;

// Enqueue BLOCK_SIZE values in order
void enqueueThreadMethod(boost::lockfree::queue<int32_t> *queue, int threadID) {
    int start = BLOCK_SIZE * threadID;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        while (!queue->push(start + i))
            ;
    }
}

// Dequeue BLOCK_SIZE values.  Note that the values returned may come from
// different enqueuers, but for each enqueuer they should be in increasing
// order.
void dequeueThreadMethod(
    boost::lockfree::queue<int32_t> *queue,
    std::array<int32_t, NUM_THREADS * BLOCK_SIZE> *retValues) {
  std::vector<int> localMax(NUM_THREADS, -1);
    /* for (int i = 0; i < BLOCK_SIZE; i++) { */
    /*     while (!queue->pop((*retValues)[threadID * BLOCK_SIZE + i])) */
    /*         ; */
    /* } */
    uint count = 0;
    bool ret = false;
    while (true) {
      ret = queue->pop((*retValues)[count]);
      if (ret) {
         int localValue = (*retValues)[count];
         int index = localValue / BLOCK_SIZE;

         if (localValue < localMax[index]) {
           std::cout << "Out of order values: " << localValue << " < "
             << localMax[index] << ", index: " << index << std::endl;
         }
         localMax[index] = localValue;
         count++;
      }

      if (count >= NUM_THREADS * BLOCK_SIZE) {
        std::cout << " done check retValues " << std::endl;
        break;
      }
    }
}

int main(int argc, char **argv) {
    std::array<int32_t, NUM_THREADS * BLOCK_SIZE> retValues;

    std::vector<std::thread> threadVector;

    boost::lockfree::queue<int32_t> queue(10000);

    // Enqueue and dequeue relatively simulataniously. And yes, we could make
    // this more robust by adding a barrier, but it works as-is
    for (int i = 0; i < NUM_THREADS; i++) {
        threadVector.emplace_back(&enqueueThreadMethod, &queue, i);
        /* threadVector.emplace_back(&dequeueThreadMethod, &queue, &retValues, i); */
    }
    threadVector.emplace_back(&dequeueThreadMethod, &queue, &retValues);

    for (std::thread &t : threadVector) {
        t.join();
    }

    // Now validate the values we dequeued.   All we are checking is
    // that for each enqueuer, its values only increase...i.e. we
    // are checking for out-of-order conditions
    /* for (int i = 0; i < NUM_THREADS; i++) { */
    /*     // vector of last-seen values by enqueuer. Each */
    /*     // entry should increase */
    /*     std::vector<int> localMax(NUM_THREADS, -1); */

    /*     // check the values dequeued by a single dequeuer */
    /*     for (int j = 0; j < BLOCK_SIZE; j++) { */
    /*         int localValue = retValues[i * BLOCK_SIZE + j]; */
    /*         int index = localValue / BLOCK_SIZE; */

    /*         if (localValue < localMax[index]) { */
    /*             std::cout << "Out of order values: " << localValue << " < " */
    /*                       << localMax[index] << " i: " << i << ", j: " << j */
    /*                       << ", index: " << index << std::endl; */
    /*         } */
    /*         localMax[index] = localValue; */
    /*     } */
    /* } */

    // Now sort all the dequeued values and make sure there are none missing
    // or duplicated
    std::sort(retValues.begin(), retValues.end());
    for (int i = 0; i < (BLOCK_SIZE * NUM_THREADS); i++) {
        if (retValues[i] != i) {
            std::cout << "Error checking sorted values at index " << i
                      << std::endl;
        }
    }

    return 0;
}
