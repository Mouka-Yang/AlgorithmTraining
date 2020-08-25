/*
Validate IP Address

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        auto len = IP.size();
        auto start = 0, end = 0, level = 0, num_len = 0, cur_num = 0;
        if (IP.find('.') != string::npos){
            for (; end <= len; end++){
                if (IP[end] == '.' || end == len){
                    if (num_len == 0||
                        num_len > 1 && IP[start] == '0' ||
                        cur_num > 255){
                            return "Neither";
                        }
                    else{
                        num_len = 0;
                        cur_num = 0;
                        start = end + 1;
                        level++;
                    }
                }
                else if (isdigit(IP[end]) && num_len < 3){
                    cur_num = cur_num * 10 + (IP[end] - '0');
                    num_len++;
                }
                else    
                    return "Neither";
            }
            return level == 4? "IPv4" : "Neither";
        }
        else if (IP.find(':') != string::npos){
            transform(IP.begin(), IP.end(), IP.begin(), ::tolower);
            for (; end <= len; end++){
                if (IP[end] == ':' || end == len){
                    if (num_len == 0 ||
                        num_len > 4 /*||
                        cur_num == 0 && (num_len > 1 && num_len < 4 )*/){
                            return "Neither";
                        }
                    else{
                        num_len = 0;
                        cur_num = 0;
                        start = end+1;
                        level++;
                    }
                }
                else if (isalnum(IP[end]) && IP[end] <= 'f' && num_len < 4){
                    if (IP[end] != '0') cur_num = 1;
                    num_len++;
                }
                else 
                    return "Neither";
            }
            return level == 8 ? "IPv6" : "Neither";
            
        }
        else 
            return "Neither";
    }
};