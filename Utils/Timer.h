#include <time.h>
#include <sys/time.h>

class Timer
{
    private:
        Timer() = default;
    public:
        static Timer& get() {
            static Timer instance;
            return instance;
        }

        void set_clock() {
            gettimeofday(&start, NULL);
        }

        float elapsed_time() {
            gettimeofday(&end, NULL);

            float elapsed = (end.tv_sec - start.tv_sec);
            elapsed += (float)(end.tv_usec - start.tv_usec) / 1000000.0;
            return elapsed;
        }

    private:
        struct timeval start;
        struct timeval end;
};
