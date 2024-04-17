#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

const string msg1 = "1010110010011110011111101110011001101100111010001111011101101011101000110010011000000101001110111010010111100100111101001010000011000001010001001001010000000010101001000011100100010011011011011011010111010011000101010111111110010011010111001001010101110001111101010000001011110100000000010010111001111010110000001101010010110101100010011111111011101101001011111001101111101111000100100001000111101111011011001011110011000100011111100001000101111000011101110101110010010100010111101111110011011011001101110111011101100110010100010001100011001010100110001000111100011011001000010101100001110011000000001110001011101111010100101110101000100100010111011000001111001110000011111111111110010111111000011011001010010011100011100001011001101110110001011101011101111110100001111011011000110001011111111101110110101101101001011110110010111101000111011001111";

const string msg2 = "1011110110100110000001101000010111001000110010000110110001101001111101010000101000110100111010000010011001100100111001101010001001010001000011011001010100001100111011010011111100100101000001001001011001110010010100101011111010001110010010101111110001100010100001110000110001111111001000100001001010100011100100001101010101111000100001111101111110111001000101111111101011001010000100100000001011001001010000101001110101110100001111100001011101100100011000110111110001000100010111110110111010010010011101011111111001011011001010010110100100011001010110110001001000100011011001110111010010010010110100110100000111100001111101111010011000100100110011111011001010101000100000011111010010110111001100011100001111100100110010010001111010111011110110001000111101010110101001110111001110111010011111111010100111000100111001011000111101111101100111011001111";

int powers[7] = {1, 2, 4, 8, 16, 32, 64};

void print_vector(vi v);

void load_vectors(vector<int> &v1, vector<int> &v2)
{
    for(int a = 0; a < msg1.size(); a++)
    {
	if(msg1[a] == '0')
	    v1.push_back(0);
	else
	    v1.push_back(1);
	if(msg2[a] == '0')
	    v2.push_back(0);
	else
	    v2.push_back(1);
    }
}


string bits_to_string(vi bits)
{
    int count = 0;
    string s = "";
    char letter = 0;
    for(int a = 0; a < bits.size(); a++)
    {
	letter += bits[a] * powers[6-count];
	count++;
	count %= 7;
	if(count == 0)
	{
	    s += letter;
	    letter = 0;
	}
    }
    return s;
}

void print_vector(vi v)
{
    for(int a = 0; a < v.size(); a++)
	cout<<v[a]<<" ";
}

vector<int> char_to_bits(char c)
{
    vi list;
    while(c != 0)
    {
	if(c % 2 == 0)
	    list.push_back(0);
	else
	    list.push_back(1);
	c /= 2;
    }
    reverse(list.begin(), list.end());
    return list;
}


vector<int> string_to_bits(string s)
{
    vi list;
    for(int a = 0; a < s.size(); a++)
    {
	vi temp = char_to_bits(s[a]);
	list.insert(list.end(), temp.begin(), temp.end());
    }
    return list;
}

/*vi string_to_bytes(string s)
{
    vi list;
    for(int a = 0; a < s.size(); a++)
	list.push_back((int)s[a]);
    return list;
}*/

vi list_to_bytes(vi list)
{
    vi bytes;
    int counter = 0;
    int pow = 6;
    for(int a = 0; a < list.size(); a++)
    {
	counter += list[a]*powers[pow];
	pow--;
	if(pow < 0)
	{
	    pow = 6;
	    bytes.push_back(counter);
	    counter = 0;
	}
    }
    return bytes;
}

bool all_letter(string s)
{
    for(int a = 0; a < s.size() ;a++)
    {
	if(!(isalpha(s[a]) || s[a] == ' '))
	    return false;
    }
    return true;
}

void iterate(vi m1, vi m2, string word)
{
    string the = word;
    vi key;
    print_vector(m1);
    cout<<endl;
    print_vector(m2);
    for(int a = 0; a <= m1.size()-the.size(); a++)
    {
	
	string decode = "";
	for(int b = 0; b < the.size(); b++)
	{
	    int k = m1[a+b] ^ the[b];
	    key.push_back(k);
	    decode += (char)(k ^ m2[a+b]);
	}
	if(all_letter(decode))
	{
	    cout<<endl<<"pos "<<a<<endl<<endl<<"WORD ";
	    cout<<decode<<endl;
	    cout<<endl;
	}	
	//cout<<decode<<endl;
	//print_vector(key);
	key.clear();
	
    }
}

vi encode(vi key, string msg)
{
    vi v;
    for(int a = 0; a < msg.size(); a++)
	v.push_back(key[a] ^ msg[a]);
    return v;
}

int main(int argc, char * argv[])
{
    freopen("message.txt", "w", stdout);
    vector<int> msg1_bits, msg2_bits, m1_bytes, m2_bytes;
    load_vectors(msg1_bits, msg2_bits);
    vector<int> key(msg1.size(), 0);
    m1_bytes = list_to_bytes(msg1_bits);
    m2_bytes = list_to_bytes(msg2_bits);
    vi test = string_to_bits("he");
    /*cout<<"SIZE "<<msg1_bits.size()<<endl;
    string s1 = "the house";
    string s2 = "test  the";
    vi key2(s1.size(), 130);
    vi c1 = encode(key2, s1);
    vi c2 = encode(key2, s2);*/
    //print_vector(test);
    //cout<<endl;
    /*print_vector(list_to_bytes(msg1_bits));
    cout<<endl;
    print_vector(list_to_bytes(msg2_bits));*/
    cout<<(int)' '<<endl;
    iterate(m1_bytes, m2_bytes, argv[1]);
    //iterate(c1, c2);
    return 0;
}
