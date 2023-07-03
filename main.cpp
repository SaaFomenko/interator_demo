#include <iostream>
#include <vector>

static const unsigned int chars_size = 32;
static const std::string fail_chars_to_int = "Ошибка ввода целого числа!";

class MyException : public std::exception
{
	private:
	const std::string msg;

	public:
		MyException(const std::string msg_) : msg(msg_){}
		virtual ~MyException(){}

		const char* what() const noexcept override
		{
			return msg.c_str();
		}
};

std::vector<int> chars_to_ints(const char* chars, char divider)
{
    unsigned int i = 0;
    unsigned int j = 0;
    char sub_chars[chars_size]{};
    bool isCharsNull = false;
    bool isSubCharsNull = false;

    std::vector<int> result{};

    while (!isCharsNull)
    {
        isCharsNull = static_cast<unsigned int>(chars[i]) == 0;
        isSubCharsNull = isCharsNull || chars[i] == divider;
        while (!isSubCharsNull)
        {
            isSubCharsNull = static_cast<unsigned int>(sub_chars[i]) == 0;
            sub_chars[j] = chars[i];
            ++j;
            ++i;
        }

        if (j != 0)
        {
            result.push_back(atoi(sub_chars));
        }
        j = 0;
        ++i;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    const char* in_msg = "[IN]: ";
    const char* out_msg = "[OUT]: ";
    const char divider = ' ';

    std::string text = "";

    std::cout << in_msg;
    std::getline(std::cin, text);

    const unsigned int size = text.length();

    const char* chars = text.c_str();

    std::vector<int> arr = chars_to_ints(chars, divider);

    std::cout << out_msg;

    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';

    return 0;
}
