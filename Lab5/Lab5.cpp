#include <iostream>
#include <string>
#include <cmath>
#include <vector>

bool isPrime(long long num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (long long i = 5; i * i <= num; i = i + 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}
    // Функция для нахождения НОД
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int findE(int f) {
    for (int i = 2; i < f; ++i) {
        if (gcd(f, i) == 1) {
            return i;
        }
    }
    return -1;
}
int findD(int e, int f) {
    int d = 0;
    int temp = 1;
    while (true)
    {
        temp += f;
        if (temp % e == 0) {
            d = temp / e;
            return d;
        }
    }
}
//std::vector<unsigned long long> toBlocks(const std::string& str, int n) {
//    std::vector<unsigned long long> blocks;
//    std::string currentBlockStr;
//
//    for (char digitChar : str) {
//        std::string digitStr(1, digitChar); // Convert char digit to string
//
//        // Check if appending the next digit to currentBlockStr would exceed maxBlockValue
//        if (!currentBlockStr.empty() && std::stoi(currentBlockStr + digitStr) > n-1) {
//            // Add the current block to the blocks vector
//            blocks.push_back(std::stoi(currentBlockStr));
//            currentBlockStr = ""; // Reset currentBlockStr
//        }
//
//        currentBlockStr += digitStr; // Append digit to current block
//    }
//
//    // Add the last block
//    if (!currentBlockStr.empty())
//        blocks.push_back(std::stoi(currentBlockStr));
//
//    return blocks;
//}
//std::vector<unsigned long long> encryption(const std::string& msg, int e, int n) {
//    std::string encrypted;
//    int ch;
//    std::string numericString;
//    std::vector<int> numericMessage;
//    for (int i = 0; i < msg.length(); ++i) {
//        if (msg[i] == ' ') {
//            ch = 26;
//        } else {
//            ch = msg[i] - 'a' + 1;
//        }
//        std::cout << ch << ' ';
//        numericString += std::to_string(ch);
//    }
//    std::cout<<std::endl;
//    std::cout<<numericString;
//    
//    std::cout << std::endl;
//    
//    std::vector<unsigned long long> blocks = toBlocks(numericString, n);
//    for (auto block : blocks) {
//        std::cout << block << ' ';
//    }
//    std::cout << std::endl;
//    
//    std::vector<unsigned long long> chiferedBlocks;
//    for (int i = 0; i < blocks.size(); ++i) {
//        unsigned long long temp = pow(blocks[i],e);
//        temp %= n;
//        chiferedBlocks.push_back(temp);
//    }
//    for (auto chifered: chiferedBlocks) {
//        std::cout << chifered << ' ';
//    }
//    std::cout << std::endl;
//
//    return chiferedBlocks;
//}
//
//void decryption(std::vector<unsigned long long>& blocks, int d, int n) {
//    std::vector<char> decrypted;
//    std::cout << std::endl;
//    for (int i = 0; i < blocks.size(); ++i) {
//        unsigned long long temp = pow(blocks[i], d);
//        temp %= n;
//        std::cout << temp << ' ';
//        decrypted.push_back(temp + 'a' - 1);
//    }
//    std::cout<<std::endl;
//    for (auto decrypt : decrypted) {
//        std::cout << decrypt;
//    }
//    
//}
std::vector<unsigned long long> encryption(const std::string& msg, int e, int n) {
    std::vector<unsigned long long> chiferedBlocks;
    for (char ch : msg) {
        int numericValue;
        if (ch == ' ') {
            numericValue = 26; // Set numericValue for space
        }
        else {
            numericValue = ch - 'a'; // Convert character to numeric value
        }
        unsigned long long encryptedValue = 1;
        for (int i = 0; i < e; ++i) {
            encryptedValue = (encryptedValue * numericValue) % n; // Encryption formula
        }
        chiferedBlocks.push_back(encryptedValue); // Store encrypted value
    }
    return chiferedBlocks;
}

void decryption(std::vector<unsigned long long>& blocks, int d, int n) {
    for (unsigned long long block : blocks) {
        unsigned long long decryptedValue = 1;
        for (int i = 0; i < d; ++i) {
            decryptedValue = (decryptedValue * block) % n; // Decryption formula
        }
        char decryptedChar;
        if (decryptedValue == 26) {
            decryptedChar = ' '; // Set decrypted character for space
        }
        else {
            decryptedChar = decryptedValue  + 'a'; // Convert numeric value to character
        }
        std::cout << decryptedChar;
    }
    std::cout << std::endl;
}
void algorithm() {
    int p = 0, q = 0;
    bool flag = false;
    while (flag == false) {
        std::cout<<"input prime number p->"<<' ';
        std::cin>>p;
        if (isPrime(p) == false) {
            std::cout<<"number is not prime"<<' ';
        }
        else {
            flag = true;
        }
    }
    //std::cout<<p<<std::endl;
    
    flag = false;
    while (flag == false) {
        std::cout << "input prime number q->" << ' ';
        std::cin >> q;
        if (isPrime(q) == false) {
            std::cout << "number is not prime" << ' ';
        }
        else {
            flag = true;
        }
    }
    //std::cout << q << std::endl;

    int n = q*p;
    std::cout << "n: " << n << std::endl;
    int f = (p-1)*(q-1);
    std::cout << "phi: " << f << std::endl;
    int e = findE(f);
    std::cout << "E: " << e << std::endl;
    int d = findD(e, f);
    std::cout << "D: " << d << std::endl;
    std::string text;
    std::cout << "input your text for encryption ->" << ' ';
    std::cin.ignore();
    std::getline(std::cin, text);
    std::vector<unsigned long long> encrypted = encryption(text, e, n);
    for (auto encr : encrypted) {
        std::cout<<encr;
    }
    std::cout<<std::endl;
    decryption(encrypted, d, n);
}



int main()
{

    //std::cout << "Hello World!\n";
    algorithm();
}


