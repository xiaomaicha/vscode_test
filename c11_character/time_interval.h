//
// Created by wuqi on 19-6-30.
//

#ifndef VS_TEST_C11_CHARACTER_TIME_INTERVAL_H
#define VS_TEST_C11_CHARACTER_TIME_INTERVAL_H

#include <iostream>
#include <memory>
#include <vector>

#include <string>
#ifdef GCC
#include <sys/time.h>
#else
#include <ctime>
#endif // GCC

class TimeInterval {
public:
  TimeInterval(const std::string &d) : detail(d) {
    init();
  }

  TimeInterval() {
    init();
  }

  ~TimeInterval() {
#ifdef GCC
    gettimeofday(&end, NULL);
        std::cout << detail
            << 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000
            << " ms" << endl;
#else
    end = clock();
    std::cout << detail
              << (double) (end - start) / CLOCKS_PER_SEC * 1000<< " ms" << std::endl;
#endif // GCC
  }

protected:
  void init() {
#ifdef GCC
    gettimeofday(&start, NULL);
#else
    start = clock();
#endif // GCC
  }
private:
  std::string detail;
#ifdef GCC
  timeval start, end;
#else
  clock_t start, end;
#endif // GCC
};

#define TIME_INTERVAL_SCOPE(d)   std::shared_ptr<TimeInterval> time_interval_scope_begin = std::make_shared<TimeInterval>(d)

#endif //VS_TEST_C11_CHARACTER_TIME_INTERVAL_H
