#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class usernametab{
private:
    vector<bool> ht;
    int m;

    int h1(const string& s){
        unsigned long long sum = 0;
        for (int i = 0; i < s.length(); i++){
            sum += s[i] % m;
        }
        return sum % m;
    }

    int h2(const string& s){
        unsigned long long sum = 1;
        for (int i = 0; i < s.length(); i++){
            sum += int(s[i] * pow(19,i)) % m;
        }
        return sum % m;
    }

    int h3(const string& s){
        unsigned long long sum = 7;
        for (int i = 0; i < s.length(); i++){
            sum += int(s[i] * pow(30,i)) % m;
        }
        return sum % m;
    }

    int h4(const string& s){
        unsigned long long sum = 3;
        int p = 7;
        for (int i = 0; i < s.length(); i++){
            sum += int (s[i] * pow(3,i) * pow(p,i)) % m;
        }
        return sum % m;
    }

public:
    usernametab(int size) : m(size), ht(size) {}

    void insert(const string& s){
        int ind1 = h1(s);
        int ind2 = h2(s);
        int ind3 = h3(s);
        int ind4 = h4(s);
        
        ht[ind1] = true;
        ht[ind2] = true;
        ht[ind3] = true;
        ht[ind4] = true;
    }

    string search(const string& s){
        int ind1 = h1(s);
        int ind2 = h2(s);
        int ind3 = h3(s);
        int ind4 = h4(s);

        if(ht[ind1] == true && ht[ind2] == true && ht[ind3] == true && ht[ind4] == true){
            return ("Element je vjerojatno u tablici");

        }else{
            return ("Element nije u tablici");
        }
    }
};

int main(){
    usernametab n(100);

    vector<string> usernames = {
        "jopis107", "hstranput", "Matej293", "MateaCucman", "JosipCestar", 
        "lanamak", "DanijelaValjak", "filipuranjek", "domagojziros", "lsanic",
        "TomislavVinkovic", "IvoSusac", "matej2810", "KresimirSecan", 
        "inespejic", "InesSimunovic", "IvanFrantal", "Frle001", "inesstrapac", 
        "mkolak", "Dpritisa", "istvavk", "mtoldi", "lbrodar5", "mkristic", 
        "andreamatasovic", "balentovicanja", "IvanaVinkovic", "prakidzija", 
        "DMV1204", "JMesaric", "KarloKampic", "jurick1910", "LarisaDarojkovic"
    };
    for (auto& username : usernames)
    {
        n.insert(username);
    }

    cout << n.search("InesSimunovic") << endl;
    cout << n.search("jurick1910") << endl;
    
    cout << n.search("ovoneradi") << endl;
    return 0;
}