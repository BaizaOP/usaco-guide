#include <bits/stdc++.h>

using namespace std;

vector<bool> swap_places (vector<bool> anime, int a, int b);
int iteration (vector<pair<int,int>> instructions, vector<int> guesses, vector<bool> anime);

int main()
{
    string name = "shell"; // edit this line with correct name
    string in = name + ".in";
    string out = name + ".out";
    
    ifstream fin(in);
    ofstream fout(out);

    int n; fin >> n;
    vector<pair<int, int>> instructions;
    vector<int> guesses;
    for(int i = 0; i < n; i++) 
    {
        int a, b, c; fin >> a >> b >> c;
        instructions.push_back(make_pair(a,b));
        guesses.push_back(c);
    }
    for(int i = 0; i < instructions.size(); i++)
    {
        cout << i + 1 << ": " << instructions[i].first << " -> " << instructions[i].second << endl;        
    }
    
    int tff = iteration(instructions, guesses, {true, false, false});  
    int ftf = iteration(instructions, guesses, {false, true, false});  
    int fft = iteration(instructions, guesses, {false, false, true});  
    int max_num = max(max(tff, ftf), fft);
    cout << "the max is: " << max_num << endl;
    fout << max_num << endl;
    return 0;
}

int iteration (vector<pair<int,int>> instructions, vector<int> guesses, vector<bool> anime) 
{
    int correct = 0; 
    for(int i = 0; i < instructions.size(); i++)
    {
        swap_places(anime, instructions[i].first, instructions[i].first);
       
        int guess_loc = guesses[i];
        if(anime[guess_loc])
            correct++;
    }
    return correct;
}

vector<bool> swap_places (vector<bool> anime, int a, int b) 
{
    bool temp = anime[a];
    anime[a] = anime[b];
    anime[b] = temp;
    return anime;
}
