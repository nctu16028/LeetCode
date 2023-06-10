#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string charMap;
    int counter;
    unordered_map<string, string> urlDB;

    Solution() {
        srand(time(0));
        charMap = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        counter = rand() % (62 * 62 * 62 * 62 * 62);
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/";
        int i = counter;
        while (i > 0)
        {
            shortUrl += charMap[i % 62];
            i /= 62;
        }
        urlDB.insert({shortUrl, longUrl});
        counter++;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlDB[shortUrl];
    }
};

int main()
{
    string url;
    cin >> url;

    Solution* obj = new Solution();
    string tiny = obj->encode(url);
    string ans = obj->decode(tiny);
    cout << tiny << endl;
    cout << ans << endl;
    delete obj;

    return 0;
}
