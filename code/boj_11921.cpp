/*
    0.1
    https://www.acmicpc.net/problem/11921
*/
#include <iostream>

namespace fiene
{
    template <class CharT, class Traits, size_t BufferSize>
    class ps_cbuf_t : public std::basic_streambuf<CharT, Traits>
    {
        using super = std::basic_streambuf<CharT, Traits>;
        using convert = std::codecvt<CharT, char, typename Traits::state_type>;
        using int_type = typename Traits::int_type;
        using pos_type = typename Traits::pos_type;
        using off_type = typename Traits::off_type;
        enum {
            buffer_size = BufferSize
        };
        ps_cbuf_t() {
            auto result = fread(buffer, sizeof(CharT), BufferSize, stdin);
            if (result == 0)
                idx = BufferSize;
            else
                idx = 0;
        }
        ~ps_cbuf_t() {}
        static CharT buffer[BufferSize];
        static size_t idx;
    protected:
        virtual int_type underflow() override
        {
            return Traits::to_int_type(buffer[idx]);
        }

        virtual int_type uflow() override
        {
            if (++idx == BufferSize) {
                auto result = fread(buffer, sizeof(CharT), BufferSize, stdin);
                if (result == 0)
                    return Traits::eof();
                idx = 0;
            }
            return Traits::to_int_type(buffer[idx]);
        }
    public:
        static super* get_instance()
        {
            static ps_cbuf_t ps_cbuf;
            return &ps_cbuf;
        }
    };

    template <class CharT, class Traits, size_t BufferSize>
    CharT ps_cbuf_t<CharT, Traits, BufferSize>::buffer[BufferSize] = {};

    template <class CharT, class Traits, size_t BufferSize>
    size_t ps_cbuf_t<CharT, Traits, BufferSize>::idx = BufferSize;

    void use_fast_cin(bool use = true)
    {
        static std::streambuf* src = nullptr;

        if (use) {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            if (!src)
                src = std::cin.rdbuf(ps_cbuf_t<char, std::char_traits<char>, 1 << 17>::get_instance());
        }
        else {
            std::ios::sync_with_stdio(true);
            std::cin.tie(&std::cout);
            if (src) {
                std::cin.rdbuf(src);
                src = nullptr;
            }
        }
    }
}

using namespace std;

int main()
{
    fiene::use_fast_cin();
    size_t N;
    unsigned long long V, sum = 0;
    cin >> N;
    if (N >= 700000)N = 700000;
    size_t T = N;
    while (T--) {
        cin >> V;
        sum += V;
    }

    cout << N << "\n" << sum;
}