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
	str = encode_morse(str);

	cout << str.buf << endl;

	morse_string decoded_str = decode_morse(str);
	cout << decoded_str.buf << endl;
	return 0;
}
