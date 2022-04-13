// morse_decoder.cpp : Defines the entry point for the application.
//

#include "morse_decoder.h"

#include <iostream>
using namespace std;

int main()
{
	morse_string str;
	str.buf = "sos";
	str.is_dots_and_dashes = false;

	size_t check_len = encode_morse_length(str);
	str = encode_morse(str);

	cout << str.buf << '\n';
	cout << check_len << '\n';
	cout << ((check_len == 27) ? "length ok" : "length not ok") << "\n\n";

	size_t decode_check_len = decode_morse_length(str);
	morse_string decoded_str = decode_morse(str);

	cout << decoded_str.buf << '\n';
	cout << decode_check_len << '\n';
	cout << ((decode_check_len == 3) ? "length ok" : "length not ok") << "\n\n";

	return 0;
}
