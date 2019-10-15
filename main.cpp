#include <iostream>
#include <chrono>
#include <ctime>

//-fsave-optimization-record[=<format>]
//Write optimization remarks to a separate file.

//This option, which defaults to off, controls whether Clang writes optimization reports to a separate file. By recording diagnostics in a file, users can parse or sort the remarks in a convenient way.

//By default, the serialization format is YAML.

//The supported serialization formats are:

void f (std::chrono::seconds d)
{
    std::cout << d.count() << "s \n";
}


void f_ms (std::chrono::milliseconds d)
{
    std::cout << d.count() << "ms \n";
}


void f_min (std::chrono::minutes d)
{
    std::cout << d.count() << "min \n";
}


int main(void)
{
    using namespace std::chrono;
    {
    // Just for practice purposes
    std::cout<<"hello, world"<<"\n";
    std::cout<<"hello, world"<<"\n";
    seconds sec{3};

    // Auto works with these semantics
    auto time = 20s;

    // Function takes like normal
    f(3s);
    f(time);

    // Cool
    constexpr auto time_limit = 20ns;

    // Range is good
    seconds min = seconds::min();
    seconds MAX = seconds::max();

    f(min);
    f(MAX);


    //Safe transfer from seconds to ms
    f_ms(3s);
    f_ms(time);

    // Minutes DOES NOT WORK HAHAH
//    f_min(3s);
//    f_min(time);


    time_point<system_clock, seconds> tp{10000s};
    time_t time_now = system_clock::to_time_t(tp);

    std::cout<< std::ctime(&time_now) <<"\n\n"; // NOTE time_now has to be passed by reference
    }

}
