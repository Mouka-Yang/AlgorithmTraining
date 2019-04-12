#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
using namespace std;
/* 535. Encode and Decode TinyURL */
/*
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
const string tinyhead = "http://t.cn/";
const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int short_size = 6;
class TinyUrl {
public:


	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		while (long2short.find(longUrl) == long2short.end()) {
			// New long url
			string shortUrl = "";
			srand(time(0));
			for (auto i = 0; i < short_size; i++) {
				shortUrl += alphabet[rand() % alphabet.length()];
			}
			if (short2long.find(shortUrl) == short2long.end()) {
				long2short.emplace(longUrl, shortUrl);
				short2long.emplace(shortUrl, longUrl);
			}
		}

		return tinyhead + long2short[longUrl];
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		string shorturl = string(shortUrl.end() - 6, shortUrl.end());
		if (short2long.find(shorturl) != short2long.end()) {
			return short2long[shorturl];
		}
		return "";
	}
private:
	unordered_map<string, string> long2short;
	unordered_map<string, string> short2long;
};

int main() {
	TinyUrl test;
	cout << test.encode("baidu.com") << endl
		<< test.decode(test.encode("baidu.com")) << endl;
}