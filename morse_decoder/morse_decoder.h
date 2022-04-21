// morse_decoder.h : Include file for standard system include files,
// or project specific include files.

#pragma once
//#include <array>
#include <cstdint>
#include <string>
#include <string_view>

#if __cplusplus
#define CXX_CONSTEXPR constexpr
#else
#define CXX_CONSTEXPR
#endif

enum morse_dd {
	blank,
	dot,
	dash
};

struct morse_string {
	std::string buf;
	bool is_dots_and_dashes;
};

/*
Morse Code:
dot  = 1 unit of time
dash = 3 units of time
upper and lower case are the same

an encoded character will be spaced out with dots
*/

//0-25 letters, 26-35 numbers, 36 letter space, 37 word space
CXX_CONSTEXPR const uint8_t morse_id_table[256] = {
	255,        // 0: non printable characters 0 - 31
	255,     // 1: header start
	255,     // 2: text start
	255,     // 3: text end
	255,     // 4: transmission end
	255,     // 5: enquiry
	255,     // 6: acknowledge
	255,     // 7: bell
	255,     // 8: backspace
	255,     // 9: tab \t
	255,         // 10: line feed \n
	255,       // 11: vertical tab \v
	255,       // 12: form feed \f
	255,         // 13: carriage return \r
	255,     // 14: shift out
	255,     // 15: shift in
	255,     // 16: 16 DLE
	255,     // 17: DC1
	255,     // 18: DC2
	255,     // 19: DC3
	255,     // 20: DC4
	255,     // 21: NAK
	255,     // 22: SYN
	255,     // 23: ETB
	255,     // 24: CAN
	255,     // 25: EM
	255,     // 26: SUB
	255,     // 27: ESC
	255,     // 28: FS
	255,     // 29: GS
	255,     // 30: RS
	255,     // 31: US
	36,     // 32: ' '
	255,      // 33: !
	255,     // 34: "
	255,      // 35: #
	255,      // 36: $
	255,      // 37: %
	255,      // 38: &
	255,     // 39: '
	255,      // 40: (
	255,     // 41: )
	255,       // 42: *
	255,        // 43: +
	255,      // 44: ,
	255,        // 45: -
	255,        // 46: .
	255,     // 47: /
	26,       // 48: 0
	27,        // 49: 1
	28,        // 50: 2
	29,        // 51: 3
	30,        // 52: 4
	31,        // 53: 5
	32,        // 54: 6
	33,        // 55: 7
	34,      // 56: 8
	35,      // 57: 9
	255,      // 58: :
	255,      // 59: ;
	255,      // 60: <
	255,      // 61: =
	255,      // 62: >
	255,      // 63: ?
	255,      // 64: @
	0,        // 65: a
	1,          // 66: 255,
	2,        // 67: c
	3,        // 68: d
	4,          // 69: e
	5,        // 70: f
	6,       // 71: g
	7,       // 72: h
	8,       // 73: i
	9,       // 74: j
	10,       // 75: k
	11,       // 76: l
	12,       // 77: m
	13,       // 78: n
	14,       // 79: o
	15,          // 80: 16
	16,       // 81: q
	17,          // 82: r
	18,       // 83: s
	19,       // 84: t
	20,       // 85: u
	21,       // 86: v
	22,       // 87: w
	23,          // 88: x
	24,       // 89: y
	25,       // 90: z
	255,      // 91: [
	255,     // 92: \ escape
	255,     // 93: ]
	255,      // 94: ^
	255, // 95: _
	255,      // 96: tkn_backtick,   // 32
	0,        // 97: a (lowercase)
	1,          // 98: b
	2,        // 99: c
	3,        // 100: d
	4,          // 101: e
	5,        // 102: f
	6,       // 103: g
	7,       // 104: h
	8,       // 105: i
	9,       // 106: j
	10,       // 107: k
	11,       // 108: l
	12,       // 109: m
	13,       // 110: n
	14,       // 111: o
	15,          // 112: p 16
	16,       // 113: q
	17,          // 114: r
	18,       // 115: s
	19,       // 116: t
	20,       // 117: u
	21,       // 118: v
	22,       // 119: w
	23,          // 120: x
	24,       // 121: y
	25,       // 122: z
	255,      // 123: {
	255,      // 124: |
	255,     // 125: }
	255,      // 126: ~
	255,     // 127: del
	255,        // 80: 64 128 - 255 non ascii characters
	255,        // 81
	255,        // 82
	255,        // 83
	255,        // 84
	255,        // 85
	255,        // 86
	255,        // 87
	255,        // 88
	255,        // 89
	255,        // 8A
	255,        // 8B
	255,        // 8C
	255,        // 8D
	255,        // 8E
	255,        // 8F
	255,        // 90
	255,        // 91
	255,        // 92
	255,        // 93
	255,        // 94
	255,        // 95
	255,        // 96
	255,        // 97
	255,        // 98
	255,        // 99
	255,        // 9A
	255,        // 9B
	255,        // 9C
	255,        // 9D
	255,        // 9E
	255,        // 9F
	255,        // A0
	255,        // A1
	255,        // A2
	255,        // A3
	255,        // A4
	255,        // A5
	255,        // A6
	255,        // A7
	255,        // A8
	255,        // A9
	255,        // AA
	255,        // AB
	255,        // AC
	255,        // AD
	255,        // AE
	255,        // AF
	255,        // B0
	255,        // B1
	255,        // B2
	255,        // B3
	255,        // B4
	255,        // B5
	255,        // B6
	255,        // B7
	255,        // B8
	255,        // B9
	255,        // BA
	255,        // BB
	255,        // BC
	255,        // BD
	255,        // BE
	255,        // BF
	255,        // C0
	255,        // C1
	255,        // C2
	255,        // C3
	255,        // C4
	255,        // C5
	255,        // C6
	255,        // C7
	255,        // C8
	255,        // C9
	255,        // CA
	255,        // CB
	255,        // CC
	255,        // CD
	255,        // CE
	255,        // CF
	255,        // D0
	255,        // D1
	255,        // D2
	255,        // D3
	255,        // D4
	255,        // D5
	255,        // D6
	255,        // D7
	255,        // D8
	255,        // D9
	255,        // DA
	255,        // DB
	255,        // DC
	255,        // DD
	255,        // DE
	255,        // DF
	255,        // E0
	255,        // E1
	255,        // E2
	255,        // E3
	255,        // E4
	255,        // E5
	255,        // E6
	255,        // E7
	255,        // E8
	255,        // E9
	255,        // EA
	255,        // EB
	255,        // EC
	255,        // ED
	255,        // EE
	255,        // EF
	255,        // F0
	255,        // F1
	255,        // F2
	255,        // F3
	255,        // F4
	255,        // F5
	255,        // F6
	255,        // F7
	255,        // F8
	255,        // F9
	255,        // FA
	255,        // FB
	255,        // FC
	255,        // FD
	255,        // FE
	255         // 255 FF
};

CXX_CONSTEXPR size_t custom_strlen(const char* ptr) noexcept {
	size_t sz = 0;
	for (; *ptr != 0; ptr++, sz++);
	return sz;
}
//
CXX_CONSTEXPR const char* morse_strings[38] = {
	"* ___", //a
	"___ * * *", //b 
	"___ * ___ *", //c
	"___ * *", //d 
	"*", //e
	"* * ___ *", //f
	"___ ___ *", //g
	"* * * *", //h
	"* *", //i
	"* ___ ___ ___", //j
	"___ * ___", //k
	"* ___ * *", //l
	"___ ___", //m
	"___ *", //n
	"___ ___ ___", //o
	"* ___ ___ *", //p
	"___ ___ * ___", //q
	"* ___ *", //r
	"* * *", //s
	"___", //t
	"* * ___", //u
	"* * * ___", //v
	"* ___ ___", //w
	"___ * * ___", //x
	"___ * ___ ___", //y
	"___ ___ * *", //z
	"___ ___ ___ ___ ___", //0
	"* ___ ___ ___ ___", //1
	"* * ___ ___ ___", //2
	"* * * ___ ___", //3
	"* * * * ___", //4
	"* * * * *", //5
	"___ * * * *", //6
	"___ ___ * * *", //7
	"___ ___ ___ * *", //8
	"___ ___ ___ ___ *", //9
	"   ", //space betweeen letters 3 units
	"       " //space between words 7 units
};

CXX_CONSTEXPR char* morse_letterings[38] = {
"a",
"b",
"c",
"d",
"e",
"f",
"g",
"h",
"i",
"j",
"k",
"l",
"m",
"n",
"o",
"p",
"q",
"r",
"s",
"t",
"u",
"v",
"w",
"x",
"y",
"z",
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"", //space betweeen letters 3 units
" " //space between words 7 units
};

CXX_CONSTEXPR size_t morse_string_lengths[38] = {
	custom_strlen(morse_strings[0]),
	custom_strlen(morse_strings[1]),
	custom_strlen(morse_strings[2]),
	custom_strlen(morse_strings[3]),
	custom_strlen(morse_strings[4]),
	custom_strlen(morse_strings[5]),
	custom_strlen(morse_strings[6]),
	custom_strlen(morse_strings[7]),
	custom_strlen(morse_strings[8]),
	custom_strlen(morse_strings[9]),
	custom_strlen(morse_strings[10]),
	custom_strlen(morse_strings[11]),
	custom_strlen(morse_strings[12]),
	custom_strlen(morse_strings[13]),
	custom_strlen(morse_strings[14]),
	custom_strlen(morse_strings[15]),
	custom_strlen(morse_strings[16]),
	custom_strlen(morse_strings[17]),
	custom_strlen(morse_strings[18]),
	custom_strlen(morse_strings[19]),
	custom_strlen(morse_strings[20]),
	custom_strlen(morse_strings[21]),
	custom_strlen(morse_strings[22]),
	custom_strlen(morse_strings[23]),
	custom_strlen(morse_strings[24]),
	custom_strlen(morse_strings[25]),
	custom_strlen(morse_strings[26]),
	custom_strlen(morse_strings[27]),
	custom_strlen(morse_strings[28]),
	custom_strlen(morse_strings[29]),
	custom_strlen(morse_strings[30]),
	custom_strlen(morse_strings[31]),
	custom_strlen(morse_strings[32]),
	custom_strlen(morse_strings[33]),
	custom_strlen(morse_strings[34]),
	custom_strlen(morse_strings[35]),
	custom_strlen(morse_strings[36]),
	custom_strlen(morse_strings[37])
};

CXX_CONSTEXPR size_t morse_letterings_lengths[38] = {
	custom_strlen(morse_letterings[0]),
	custom_strlen(morse_letterings[1]),
	custom_strlen(morse_letterings[2]),
	custom_strlen(morse_letterings[3]),
	custom_strlen(morse_letterings[4]),
	custom_strlen(morse_letterings[5]),
	custom_strlen(morse_letterings[6]),
	custom_strlen(morse_letterings[7]),
	custom_strlen(morse_letterings[8]),
	custom_strlen(morse_letterings[9]),
	custom_strlen(morse_letterings[10]),
	custom_strlen(morse_letterings[11]),
	custom_strlen(morse_letterings[12]),
	custom_strlen(morse_letterings[13]),
	custom_strlen(morse_letterings[14]),
	custom_strlen(morse_letterings[15]),
	custom_strlen(morse_letterings[16]),
	custom_strlen(morse_letterings[17]),
	custom_strlen(morse_letterings[18]),
	custom_strlen(morse_letterings[19]),
	custom_strlen(morse_letterings[20]),
	custom_strlen(morse_letterings[21]),
	custom_strlen(morse_letterings[22]),
	custom_strlen(morse_letterings[23]),
	custom_strlen(morse_letterings[24]),
	custom_strlen(morse_letterings[25]),
	custom_strlen(morse_letterings[26]),
	custom_strlen(morse_letterings[27]),
	custom_strlen(morse_letterings[28]),
	custom_strlen(morse_letterings[29]),
	custom_strlen(morse_letterings[30]),
	custom_strlen(morse_letterings[31]),
	custom_strlen(morse_letterings[32]),
	custom_strlen(morse_letterings[33]),
	custom_strlen(morse_letterings[34]),
	custom_strlen(morse_letterings[35]),
	custom_strlen(morse_letterings[36]),
	custom_strlen(morse_letterings[37])
};
/*
size_t morse_transition_table[1][3] = {

}
*/

size_t encode_morse_length(const morse_string& str) {
	size_t ret = 0;

	if (str.is_dots_and_dashes) {
		//done already as dots and dashes
		return ret = str.buf.size();
	}
	else {
		//encode
		bool was_word = false;
		for (size_t i = 0; i < str.buf.size(); i++) {
			char c = str.buf[i];
			uint8_t id = morse_id_table[c];
			//0-25 letters, 26-35 numbers, 36 letter space, 37 word space space
			if (id < 36) {
				if (was_word) { // need to stick space here
					ret += morse_string_lengths[36];
				}
				ret += morse_string_lengths[id];
				was_word = true;
			}
			else {
				was_word = false;
				ret += morse_string_lengths[37];
			}
		}
	}

	return ret;
}

size_t decode_morse_length(const morse_string& str) {
	size_t ret = 0;

	if (str.is_dots_and_dashes) {
		//done already as dots and dashes
		size_t i = 0;
		for (size_t i = 0; i < str.buf.size();) {
			uint8_t decoded_id = 36;

			const char* matched = nullptr;
			size_t matched_sz = 0;

			for (size_t match_idx = 0; match_idx < 38; match_idx++) {
				const char* ptr = morse_strings[match_idx];
				size_t sz = morse_string_lengths[match_idx];
				size_t i2 = i;
				// only check for longer (better) matches
				if (sz > matched_sz) {
					bool is_matched = true;
					size_t m = 0;
					for (; m < sz && i2 < str.buf.size(); m++, i2++) {
						is_matched = is_matched && (ptr[m] == str.buf[i2]);
					}
					is_matched = is_matched && m == sz;
					if (is_matched) {
						matched = ptr;
						matched_sz = sz;
						decoded_id = match_idx;
					}
				}
			}

			if (matched) {
				i += matched_sz;
				ret += morse_letterings_lengths[decoded_id];
			}
			else {
				//nonsense pattern
				break;
			}
		}

		return ret;
	}
	else {
		//encode
		return ret = str.buf.size();
	}

	return ret;
}

morse_string encode_morse(const morse_string& str) {
	morse_string ret = str;

	if (ret.is_dots_and_dashes) {
		//done already as dots and dashes
	}
	else {
		ret.buf.clear();
		//reserve exactly enough
		ret.buf.reserve(encode_morse_length(str));

		ret.is_dots_and_dashes = true;
		//encode
		bool was_word = false;
		for (size_t i = 0; i < str.buf.size(); i++) {
			char c = str.buf[i];
			uint8_t id = morse_id_table[c];
			//0-25 letters, 26-35 numbers, 36 letter space, 37 word space space
			if (id < 36) {
				if (was_word) { // need to stick space here
					ret.buf.append(morse_strings[36], morse_string_lengths[36]);
				}
				ret.buf.append(morse_strings[id], morse_string_lengths[id]);
				was_word = true;
			}
			else {
				//id += was_word;
				was_word = false;
				ret.buf.append(morse_strings[37], morse_string_lengths[37]);
			}
		}
	}

	return ret;
}

morse_string decode_morse(const morse_string& dots_and_dashes) {
	morse_string ret = dots_and_dashes;

	if (dots_and_dashes.is_dots_and_dashes) {
		ret.buf.clear();
		ret.is_dots_and_dashes = false;
		// decode
		for (size_t i = 0; i < dots_and_dashes.buf.size();) {
			uint8_t decoded_id = 36;

			const char* matched = nullptr;
			size_t matched_sz = 0;

			for (size_t match_idx = 0; match_idx < 38; match_idx++) {
				const char* ptr = morse_strings[match_idx];
				size_t sz = morse_string_lengths[match_idx];
				size_t i2 = i;
				// only check for longer (better) matches
				if (sz > matched_sz) {
					bool is_matched = true;
					size_t m = 0;
					for (; m < sz && i2 < dots_and_dashes.buf.size(); m++, i2++) {
						is_matched = is_matched && (ptr[m] == dots_and_dashes.buf[i2]);
					}
					is_matched = is_matched && m == sz;
					if (is_matched) {
						matched = ptr;
						matched_sz = sz;
						decoded_id = match_idx;
					}
				}
			}

			if (matched) {
				ret.buf.append(morse_letterings[decoded_id], morse_letterings_lengths[decoded_id]);
				i += matched_sz;
			}
			else {
				break;
			}
		}
	}
	else {
		// done already as dots and dashes
	}

	return ret;
}

bool validate_morse(const morse_string &str) {
	bool ret = true;
	if (str.is_dots_and_dashes) {
		size_t i = 0;
		for (size_t i = 0; i < str.buf.size();) {
			uint8_t decoded_id = 36;

			const char* matched = nullptr;
			size_t matched_sz = 0;

			for (size_t match_idx = 0; match_idx < 38; match_idx++) {
				const char* ptr = morse_strings[match_idx];
				size_t sz = morse_string_lengths[match_idx];
				size_t i2 = i;
				// only check for longer (better) matches
				if (sz > matched_sz) {
					bool is_matched = true;
					size_t m = 0;
					for (; m < sz && i2 < str.buf.size(); m++, i2++) {
						is_matched = is_matched && (ptr[m] == str.buf[i2]);
					}
					is_matched = is_matched && m == sz;
					if (is_matched) {
						matched = ptr;
						matched_sz = sz;
						decoded_id = match_idx;
					}
				}
			}

			if (matched) {
				i += matched_sz;
			}
			else {
				//nonsense pattern
				ret = false;
				break;
			}
		}
		// check we've decoded everything
		ret = ret && i == str.buf.size();
		return ret;
	}
	else {
		//all characters must be alpha numeric or spaces
		for (size_t i = 0; i < str.buf.size(); i++) {
			char c = str.buf[i];
			ret = ret && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ');
		}
		return ret;
	}
}