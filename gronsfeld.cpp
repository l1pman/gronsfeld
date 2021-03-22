#include <iostream>
#include <string>
using namespace std;


string alphabet[28] = { "Aa", "Bb", "Cc", "Dd",
						 "Ee", "Ff", "Gg", "Hh",
						 "Ii", "Jj", "Kk", "Ll",
						 "Mm", "Nn", "Oo", "Pp",
						 "Qq", "Rr", "Ss", "Tt",
						 "Uu", "Vv", "Ww", "Xx",
						 "Yy", "Zz", "01", "23" };

string code = "102";


char encodeChar(char character, int shift) {
	for (int i = 0; i < 28; i++) {
		if (character == alphabet[i][0]) {
			if (i + shift > 28) {
				return alphabet[28 - i - shift][0];
			}
			else {
				return alphabet[i + shift][0];
			}
		}
		else if (character == alphabet[i][1]) {
			if (i + shift > 28) {
				return alphabet[28 - i - shift][1];
			}
			else {
				return alphabet[i + shift][1];
			}
		}
	}
	return character;
}

char decodeChar(char character, int shift) {
	for (int i = 0; i < 28; i++) {
		if (character == alphabet[i][0]) {
			if (i - shift < 0) {
				return alphabet[28 - shift + i][0];
			}
			else {
				return alphabet[i - shift][0];
			}
		}
		else if (character == alphabet[i][1]) {
			if (i - shift < 0) {
				return alphabet[28 - shift + i][1];
			}
			else {
				return alphabet[i - shift][1];
			}
		}
	}
	return character;
}

string decodeOrEncode(string str, bool encode) {
	string changedString;
	int pos = 0;
	int codeLenght = code.length() - 1;

	for (int i = 0; i < str.length(); i++) {
		int shift = (int)code[pos] - 48;
		if (encode) {
			changedString.push_back(encodeChar(str[i], shift));
		}
		else {
			changedString.push_back(decodeChar(str[i], shift));
		}
		if (pos + 1 > codeLenght) {
			pos = 0;
		}
		else {
			pos++;
		}
	}

	return changedString;
}

int main() {
	string strToEncode = "Hello, World!";

	string encodedString = decodeOrEncode(strToEncode, true);
	string decodedString = decodeOrEncode(encodedString, false);

	cout << "Encoded string: " << encodedString << endl;
	cout << "Decoded string: " << decodedString << endl;
}
